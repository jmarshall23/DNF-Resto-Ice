// dnAI.h
//

#undef DECLARE_CLASS
#define DECLARE_CLASS(x, y, z)
#include "../../dnGame/inc/dnGameClasses.h"

// This really hacky, but we need dnGameClasses to be included first, but we aren't declaring the class in this module, so welcome to Unreal is Shit reason #2022323.
#undef DECLARE_CLASS
#define DECLARE_CLASS( TClass, TSuperClass, TStaticFlags ) \
	DECLARE_BASE_CLASS( TClass, TSuperClass, TStaticFlags ) \
	friend FArchive &operator<<( FArchive& Ar, TClass*& Res ) \
		{ return Ar << *(UObject**)&Res; } \
	virtual ~TClass() \
		{ ConditionalDestroy(); } \
	static void InternalConstructor( void* X ) \
		{ new( (EInternal*)X )TClass; } \

#include "dnAIClasses.h"

//
// DnRand 
// Basically a wrapper for krand from Duke3D.
//
class DnRand
{
public:
	DnRand()
	{
		randomseed = 17;
	}

	unsigned int GetRand()
	{
		randomseed = (randomseed * 27584621) + 1;
		return(((unsigned int)randomseed) >> 16);
	}

	bool ifrnd(int val1)
	{
		return (((GetRand() >> 8) >= (255 - (val1))));
	}
private:
	int randomseed;
};

extern DnRand dnRand;