//****************************************************************************
//**
//**    IMPRAZIEL.CPP
//**    Generic 3D model importer for DukeED by Raziel
//**
//****************************************************************************
//============================================================================
//    HEADERS
//============================================================================
// Includes for Cannibal
#include "CpjMain.h"
#include "PlgMain.h"
#include "CpjFmt.h"

// Includes for Open Asset Import Library
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// C++ includes
#include <algorithm>
#include <map>
#include <vector>
#include <limits>

using namespace std;

//============================================================================
//    CONFIGURATION FLAGS
//============================================================================
#define PRESERVE_SKELETONS
#define PRESERVE_SKELETON_SEQUENCES
#define PRESERVE_GEOMETRY_MOUNT_POINTS

//============================================================================
//    PRIVATE VARIABLES
//============================================================================
// Variables related to the import process
Assimp::Importer importer;
aiString supportedFileFormats;

VVec3* loadingVerts = NULL;
NInt loadingVertCount = 0;
NDword* loadingFaces = NULL;
NInt loadingFaceCount = 0;
VVec2* loadingUVs = NULL; // Number of UVs = loadingVertCount
NByte* loadingTextureIndices = NULL; // Number of texture indices = loadingTriCount
vector<string> loadingTextures;
map<string, string> previousTextureReferenceMappings; // Used to restore previously entered Unreal texture references


// Variables related to the CPJ/Cannibal format
OCpjProject* project = NULL;
CCpjMacSection* config = NULL;
OCpjGeometry* geometry = NULL;
OCpjSurface* surface = NULL;
OCpjFrames* frames = NULL;

//============================================================================
//    IMPORTER CLASSES
//============================================================================
class __declspec(dllexport) OCpjImporterRaziel : public OCpjImporter
{
OBJ_CLASS_DEFINE(OCpjImporterRaziel, OCpjImporter);

    // OCpjImporter
    CObjClass* GetImportClass() { return(OCpjProject::GetStaticClass()); }
    NChar* GetFileExtension() {
        if (supportedFileFormats.length == 0)
            importer.GetExtensionList(supportedFileFormats);
        return (NChar*) supportedFileFormats.C_Str() + 2; // The editor already adds '*.' to the extension, so we have to skip the first 2 chars
    }
    NChar* GetFileDescription() { return "Raziel [Static Mesh Importer]"; }
    NBool Import(OObject* inRes, NChar* inFileName, NChar* outError);
};
OBJ_CLASS_IMPLEMENTATION(OCpjImporterRaziel, OCpjImporter, 0);

//============================================================================
//    PLUGIN CLASS
//============================================================================
class CImpPlugin : public IPlgPlugin
{
public:
    // IPlgPlugin
    bool Create() { return(1); }
    bool Destroy() { return(1); }
    char* GetTitle() { return("Raziel's 3D model importer"); }
    char* GetDescription() { return("This model importer uses Open Asset Importer to import a variety of different model formats into DukeED"); }
    char* GetAuthor() { return("Raziel"); }
    float GetVersion() { return(1.0f); }
};

static CImpPlugin imp_Plugin;

extern "C" __declspec(dllexport) IPlgPlugin* __cdecl CannibalPluginCreate(void)
{
    return(&imp_Plugin);
}

//============================================================================
//    PRIVATE FUNCTIONS
//============================================================================
// Related to Open Asset Import Library
const aiScene* LoadSceneWithAssImp(NChar* inFileName, NChar* outError);

// Related to importing CPJs
NBool ImportCPJFromScene(OObject* inRes, const aiScene* scene, NChar* outError);
void RemoveOldChunksFromProject();
void AddConfigGeometryAndSurfaceToProject();
void SetDefaultsInProject();
void AddLODToProject();

// Generic functions for importing 3D content
NBool PrepareGeometryAndSurfaceDataFromScene(const aiScene* scene, NChar* outError);
NBool ImportGeometryData();
NBool ImportSurfaceData();
void SetBoundingBoxSizeInConfig();
void ReleaseAllocatedMemory();

//============================================================================
//    OPEN ASSET IMPORT LIBRARY PLUGIN
//============================================================================
NBool OCpjImporterRaziel::Import(OObject* inRes, NChar* inFileName, NChar* outError)
{
#if defined _DEBUG
    //LOG_Init("Import log");  // For testing purposes, should not be enabled when used with the editor
#endif
    const aiScene* scene = LoadSceneWithAssImp(inFileName, outError);
    if (!scene) return FALSE;

    return ImportCPJFromScene(inRes, scene, outError);
}

const aiScene* LoadSceneWithAssImp(NChar* inFileName, NChar* outError)
{
    const aiScene* scene = importer.ReadFile(inFileName,
                                             aiProcess_Triangulate
                                             //| aiProcess_MakeLeftHanded
                                             | aiProcess_FlipUVs
                                             | aiProcess_FlipWindingOrder
                                             | aiProcess_PreTransformVertices
                                             | aiProcess_GenSmoothNormals
                                             | aiProcess_RemoveRedundantMaterials
                                             | aiProcess_GenUVCoords
                                             | aiProcess_TransformUVCoords
                                             //| aiProcess_OptimizeGraph
                                             //| aiProcess_OptimizeMeshes
                                             | aiProcess_JoinIdenticalVertices
    );

    if (!scene)
    {
        sprintf(outError, "Unable to open selected file: %s", importer.GetErrorString());
        return FALSE;
    }

    return scene;
}

NBool ImportCPJFromScene(OObject* inRes, const aiScene* scene, NChar* outError)
{
    if (!inRes || !inRes->IsA(OCpjProject::GetStaticClass()))
    {
        strcpy(outError, "Invalid resource");
        return FALSE;
    }
    project = (OCpjProject*)inRes;

    // Preprocess Geometry and Surface data
    if (!PrepareGeometryAndSurfaceDataFromScene(scene, outError))
    {
        ReleaseAllocatedMemory();
        return FALSE;
    }

    // Prepare CPJ project for 3D content
    RemoveOldChunksFromProject();
    AddConfigGeometryAndSurfaceToProject();

    // Import Geometry data
    if (!ImportGeometryData())
    {
        ReleaseAllocatedMemory();
        return FALSE;
    }

    // Import Surface data
    ImportSurfaceData();

    // Final cleanup on imported files
    //AddLODToProject(); // Disabled for now as the DNF2001 Restoration Project branch doesn't support LODs anyway
    SetBoundingBoxSizeInConfig();
    SetDefaultsInProject();

    // Release any allocated memory
    ReleaseAllocatedMemory();

    return TRUE;
}

void RemoveOldChunksFromProject()
{
    for (TObjIter<OCpjChunk> iter(project); iter; iter++)
    {
#ifdef PRESERVE_SKELETONS
        if (iter->IsA(OCpjSkeleton::GetStaticClass()))
            continue;
#endif
#ifdef PRESERVE_SKELETON_SEQUENCES
        if (iter->IsA(OCpjSequence::GetStaticClass()))
        {
            OCpjSequence* seq = (OCpjSequence*)*iter;
            if (seq->m_BoneInfo.GetCount())
                continue;
        }
#endif
#ifdef PRESERVE_GEOMETRY_MOUNT_POINTS
        if (iter->IsA(OCpjGeometry::GetStaticClass()))
        {
            OCpjGeometry* geo = (OCpjGeometry*)*iter;
            if (geo->m_Mounts.GetCount())
                continue;
        }
#endif
        if (iter->IsA(OCpjSurface::GetStaticClass()))
        {
            OCpjSurface* surface = (OCpjSurface*)*iter;
            for (int i = 0; i < surface->m_Textures.GetCount(); i++)
                previousTextureReferenceMappings[surface->m_Textures[i].name] = surface->m_Textures[i].refName;
        }

        // Destroy this chunk, assuming it is not a preserved chunk
        iter->Destroy();
    }
}

void AddConfigGeometryAndSurfaceToProject()
{
    OCpjConfig* mac = OCpjConfig::New(project);
    config = &mac->m_Sections[mac->m_Sections.Add()];
    config->name = "autoexec";
    config->commands.AddItem(CCorString("SetAuthor \"Unknown\""));
    config->commands.AddItem(CCorString("SetDescription \"None\""));
    config->commands.AddItem(CCorString("SetOrigin 0 0 0"));
    config->commands.AddItem(CCorString("SetScale 1 1 1"));
    config->commands.AddItem(CCorString("SetRotation 0 0 0"));

    geometry = OCpjGeometry::New(project);
    config->commands.AddItem(CCorString("SetGeometry \"default\""));

    surface = OCpjSurface::New(project);
    config->commands.AddItem(CCorString("SetSurface 0 \"default\""));
}

void AddLODToProject()
{
    OCpjLodData* mLodData = OCpjLodData::New(project);
    if (mLodData->Generate(geometry, surface))
        config->commands.AddItem(CCorString("SetLodData \"default\""));
    else
        mLodData->Destroy();
}

void SetDefaultsInProject()
{
    for (TObjIter<OCpjChunk> iter(project); iter; iter++)
    {
        iter->mIsLoaded = 1;
        if (!iter->HasName())
            iter->SetName("default");
    }
}

NBool PrepareGeometryAndSurfaceDataFromScene(const aiScene* scene, NChar* outError)
{
    // Count vertex data and ensure all geometry consists of only triangles
    for (int i = 0; i < scene->mNumMeshes; i++)
    {
        loadingVertCount += scene->mMeshes[i]->mNumVertices;
        loadingFaceCount += scene->mMeshes[i]->mNumFaces;

        for (int j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
        {
            if (scene->mMeshes[i]->mFaces[0].mNumIndices != 3)
            {
                strcpy(outError, "Import file contains non-triangular geometry. This generally means it contains lines and points which are not supported, fix the source geometry and try again.");
                return FALSE;
            }
        }
    }

    // Allocate memory for geometry data
    loadingVerts = MEM_Malloc(VVec3, loadingVertCount);
    loadingFaces = MEM_Malloc(NDword, loadingFaceCount * 3);
    loadingUVs = MEM_Malloc(VVec2, loadingVertCount);
    loadingTextureIndices = MEM_Malloc(NByte, loadingFaceCount);
    loadingVertCount = 0;   // Reset this counter which is used while preparing data
    loadingFaceCount = 0;    // Reset this counter which is used while preparing data

    // Prepare material data, in practice we map one material to one DNF2001 texture
    for (int materialNum = 0; materialNum < scene->mNumMaterials; materialNum++)
        loadingTextures.push_back(scene->mMaterials[materialNum]->GetName().C_Str());

    // Prepare geometry data
    for (int meshNum = 0; meshNum < scene->mNumMeshes; meshNum++)
    {
        aiMesh* mesh = scene->mMeshes[meshNum];

        // Handle vertices
        for (int vertex = 0; vertex < mesh->mNumVertices; vertex++)
        {
            loadingVerts[loadingVertCount + vertex].x = mesh->mVertices[vertex].x;
            loadingVerts[loadingVertCount + vertex].y = mesh->mVertices[vertex].y;
            loadingVerts[loadingVertCount + vertex].z = mesh->mVertices[vertex].z;

            // Load the UVs, if present, otherwise we create dummy UVs
            loadingUVs[loadingVertCount + vertex].x = mesh->HasTextureCoords(0) ? mesh->mTextureCoords[0][vertex].x : 0.0f;
            loadingUVs[loadingVertCount + vertex].y = mesh->HasTextureCoords(0) ? mesh->mTextureCoords[0][vertex].y : 0.0f;
        }

        for (int face = 0; face < mesh->mNumFaces; face++)
        {
            loadingFaces[(loadingFaceCount + face) * 3 + 0] = loadingVertCount + mesh->mFaces[face].mIndices[0];
            loadingFaces[(loadingFaceCount + face) * 3 + 1] = loadingVertCount + mesh->mFaces[face].mIndices[1];
            loadingFaces[(loadingFaceCount + face) * 3 + 2] = loadingVertCount + mesh->mFaces[face].mIndices[2];

            // Set the material/texture index, this is stored per-triangle in CPJ, but per-mesh in Open Asset Import Library
            loadingTextureIndices[loadingFaceCount + face] = mesh->mMaterialIndex;
        }

        // Update counts in preparation for importing the next mesh
        loadingVertCount += mesh->mNumVertices;
        loadingFaceCount += mesh->mNumFaces;
    }

    return TRUE;
}

void ReleaseAllocatedMemory()
{
    // Clear out any existing data in memory
    if (loadingVerts)
        MEM_Free(loadingVerts);
    if (loadingFaces)
        MEM_Free(loadingFaces);
    if (loadingUVs)
        MEM_Free(loadingUVs);
    if (loadingTextureIndices)
        MEM_Free(loadingTextureIndices);
    loadingVerts = NULL;
    loadingFaces = NULL;
    loadingUVs = NULL;
    loadingTextureIndices = NULL;
    loadingVertCount = 0;
    loadingFaceCount = 0;
    loadingTextures.clear();
    previousTextureReferenceMappings.clear();
}

NBool ImportGeometryData()
{
    return geometry->Generate(loadingVertCount, loadingVerts[0], loadingFaceCount, loadingFaces);
}

NBool ImportSurfaceData() {
    surface->m_Textures.Add(loadingTextures.size());
    for (int i = 0; i < loadingTextures.size(); i++)
    {
        strcpy(surface->m_Textures[i].name, loadingTextures[i].c_str());

        // Check if we previously set a texture reference for this material name, if so, use the same reference
        if (previousTextureReferenceMappings.count(surface->m_Textures[i].name))
            strcpy(surface->m_Textures[i].refName, previousTextureReferenceMappings[surface->m_Textures[i].name].c_str());
    }

    surface->m_Tris.Add(loadingFaceCount);
    surface->m_UV.AddZeroed(loadingVertCount);

    for (int i = 0; i < loadingFaceCount; i++)
    {
        CCpjSrfTri* outTri = &surface->m_Tris[i];
        outTri->uvIndex[0] = loadingFaces[i*3+0];
        outTri->uvIndex[1] = loadingFaces[i*3+1];
        outTri->uvIndex[2] = loadingFaces[i*3+2];
        outTri->texIndex = loadingTextureIndices[i];
        outTri->flags = 0;
    }

    for (int i = 0; i < loadingVertCount; i++)
    {
        surface->m_UV[i].x = loadingUVs[i].x;
        surface->m_UV[i].y = loadingUVs[i].y;
    }

    return TRUE;
}

void SetBoundingBoxSizeInConfig()
{
    CCorString command;
    VVec3 boundingBoxMin = VVec3(FLT_MAX, FLT_MAX, FLT_MAX);
    VVec3 boundingBoxMax = VVec3(-FLT_MAX, -FLT_MAX, -FLT_MAX);

    for (int i = 0; i < loadingVertCount; i++)
    {
        boundingBoxMin.x = min(boundingBoxMin.x, loadingVerts[i].x);
        boundingBoxMin.y = min(boundingBoxMin.y, loadingVerts[i].y);
        boundingBoxMin.z = min(boundingBoxMin.z, loadingVerts[i].z);

        boundingBoxMax.x = max(boundingBoxMax.x, loadingVerts[i].x);
        boundingBoxMax.y = max(boundingBoxMax.y, loadingVerts[i].y);
        boundingBoxMax.z = max(boundingBoxMax.z, loadingVerts[i].z);
    }

    command.Setf("SetBoundsMin %f %f %f", boundingBoxMin.x, boundingBoxMin.y, boundingBoxMin.z);
    config->commands.AddItem(command);
    
    command.Setf("SetBoundsMax %f %f %f", boundingBoxMax.x, boundingBoxMax.y, boundingBoxMax.z);
    config->commands.AddItem(command);
}
