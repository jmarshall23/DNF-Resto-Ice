// dnGame.cpp
//

#include <Engine.h>

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

#define DN_FORCE_NAME_EXPORT

// Register things.
#define NAMES_ONLY
#define AUTOGENERATE_NAME(name) DNAI_API FName DNAI_##name = TEXT(#name);
#define AUTOGENERATE_FUNCTION(cls,idx,name) IMPLEMENT_FUNCTION(cls,idx,name)
#include "dnAIClasses.h"
#undef AUTOGENERATE_FUNCTION
#undef AUTOGENERATE_NAME
#undef NAMES_ONLY

IMPLEMENT_PACKAGE(dnAI);

IMPLEMENT_CLASS(AEDFshield)
