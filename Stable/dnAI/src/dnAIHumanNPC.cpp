/*=============================================================================
	dnAIHumanNPC.cpp
=============================================================================*/
#include <Engine.h>

#include "dnAI.h"

IMPLEMENT_CLASS(AHumanNPC)

EAttitude AHumanNPC::AttitudeTo(AActor* Other)
{
	if (Other != nullptr && Other->IsA(APlayerPawn::StaticClass()))
	{
		return ATTITUDE_Ignore;
	}
	return ATTITUDE_Hate;
}