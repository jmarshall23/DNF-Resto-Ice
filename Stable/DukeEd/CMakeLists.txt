project(DukeEd CXX)

set(no_group_source_files
    "Src/Res/EdSplash.bmp"
)
source_group("" FILES ${no_group_source_files})

set(Inc
    "Inc/BottomBar.h"
    "Inc/Browser.h"
    "Inc/BrowserActor.h"
    "Inc/BrowserGroup.h"
    "Inc/BrowserMaster.h"
    "Inc/BrowserMesh.h"
    "Inc/BrowserMusic.h"
    "Inc/BrowserSound.h"
    "Inc/BrowserTexture.h"
    "Inc/BuildPropSheet.h"
    "Inc/ButtonBar.h"
    "Inc/CodeFrame.h"
    "Inc/DlgAddSpecial.h"
    "Inc/DlgBevel.h"
    "Inc/DlgBrushBuilder.h"
    "Inc/DlgBrushImport.h"
    "Inc/DlgBuildOptions.h"
    "Inc/DlgDepth.h"
    "Inc/DlgGeneric.h"
    "Inc/DlgMapError.h"
    "Inc/DlgMapImport.h"
    "Inc/DlgProgress.h"
    "Inc/DlgRename.h"
    "Inc/DlgScaleLights.h"
    "Inc/DlgSearchActors.h"
    "Inc/DlgTexProp.h"
    "Inc/DlgTexReplace.h"
    "Inc/DlgTexUsage.h"
    "Inc/DlgViewportConfig.h"
    "Inc/Extern.h"
    "Inc/MRUList.h"
    "Inc/SurfacePropSheet.h"
    "Inc/TerrainEditSheet.h"
    "Inc/TopBar.h"
    "Inc/TwoDeeShapeEditor.h"
    "Inc/ViewportFrame.h"
)
source_group("Header Files" FILES ${Inc})

set(Res
    "Src/Res/bb_grid1.bmp"
    "Src/Res/bb_lock1.bmp"
    "Src/Res/bb_log_w.bmp"
    "Src/Res/bb_rotat.bmp"
    "Src/Res/bb_vtx_s.bmp"
    "Src/Res/bb_zoomc.bmp"
    "Src/Res/bmp00001.bmp"
    "Src/Res/bmp00002.bmp"
    "Src/Res/bmp00003.bmp"
    "Src/Res/bmp00004.bmp"
    "Src/Res/bmp00005.bmp"
    "Src/Res/bmp00006.bmp"
    "Src/Res/bmp00007.bmp"
    "Src/Res/bmp00008.bmp"
    "Src/Res/bmp00009.bmp"
    "Src/Res/bmp00010.bmp"
    "Src/Res/bmp00011.bmp"
    "Src/Res/bmp00012.bmp"
    "Src/Res/bmp00013.bmp"
    "Src/Res/bmp00014.bmp"
    "Src/Res/bmp00015.bmp"
    "Src/Res/bmp00016.bmp"
    "Src/Res/bmp00017.bmp"
    "Src/Res/bmp00018.bmp"
    "Src/Res/bmp00019.bmp"
    "Src/Res/bmp00020.bmp"
    "Src/Res/bmp00021.bmp"
    "Src/Res/bmp00025.bmp"
    "Src/Res/bmp00026.bmp"
    "Src/Res/bmp00027.bmp"
    "Src/Res/bmp00028.bmp"
    "Src/Res/browsers.bmp"
    "Src/Res/browsert.bmp"
    "Src/Res/cf_toolb.bmp"
    "../Engine/Src/res/DukeForever.ico"
    "Src/Res/idbm_2ds.bmp"
    "Src/Res/idbm_bui.bmp"
    "Src/Res/idbm_buildall.bmp"
    "Src/Res/idbm_cam.bmp"
    "Src/Res/idbm_dow.bmp"
    "Src/Res/idbm_edi.bmp"
    "Src/Res/idbm_fil.bmp"
    "Src/Res/idbm_map.bmp"
    "Src/Res/idbm_mes.bmp"
    "Src/Res/IDBM_MUS.BMP"
    "Src/Res/idbm_pla.bmp"
    "Src/Res/idbm_sur.bmp"
    "Src/Res/idbm_tex.bmp"
    "Src/Res/idbm_unr.bmp"
    "Src/Res/idbm_vie.bmp"
    "Src/Res/toolbar1.bmp"
)
source_group("Res" FILES ${Res})

set(Src
    "Src/Main.cpp"
    "Src/Res/DukeEd.rc"
    "Src/Res/DukeEd.h"
)
source_group("Src" FILES ${Src})

add_executable(DukeEd WIN32
    ${no_group_source_files}
    ${Inc}
    ${Res}
    ${Src}
)

target_compile_definitions(DukeEd PRIVATE
    "_UNICODE" "UNICODE"
)

target_link_libraries(DukeEd PRIVATE 
    Engine 
    Editor 
    Cannibal
    $<$<BOOL:${ENABLE_BUGSLAYER}>:BugslayerUtil>
    comctl32
    winmm
)

target_link_directories(DukeEd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(DukeEd PRIVATE
    Inc
    Src
    ../Core/Inc
    ../Editor/Inc
    ../Engine/Inc
    ../Window/Inc
)
