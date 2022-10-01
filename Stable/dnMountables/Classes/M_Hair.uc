/*-----------------------------------------------------------------------------
	M_Hair
	Author: Brandon Reinhart
-----------------------------------------------------------------------------*/
class M_Hair extends MountableDecoration;

#exec OBJ LOAD FILE=..\Meshes\c_characters.dmx

defaultproperties
{
    MountType=MOUNT_MeshSurface
    MountMeshItem=hair
    Mesh=DukeMesh'c_characters.hair_long1'
    bShadowCast=False
}

// Current hair fix by Raziel
function PostBeginPlay()
{
	Super.PostBeginPlay();
	FixHairRendering();
}

function FixHairRendering()
{
	// Alpha blending settings
	Style=STY_Translucent2;
	
	// Render settings
	bUseViewPortForZ=False;
	LodMode=LOD_Disabled;
	LODBias=0.0;
	
	// Lighting settings
	MaxDesiredActorLights=5;
	bShadowReceive=True;
	bShadowCast=False;
}