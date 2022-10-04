// dnAIHumanNPC_script.cpp
//

#include <Engine.h>

#include "dnAI.h"

// int Damage, Pawn instigatedBy, vector HitLocation, vector Momentum, class<DamageType> DamageType
void AHumanNPC::execTakeDamage(FFrame& Stack, RESULT_DECL)
{
	P_GET_INT(Damage)
	P_GET_OBJECT(APawn, instigatedBy);
	P_GET_VECTOR(HitLocation);
	P_GET_VECTOR(Momentum);
	P_GET_OBJECT(UClass, DamageType);
	P_FINISH;

	if (bNPCInvulnerable)
	{
		return;
	}

	eventTakeDamageEvent(Damage, instigatedBy, HitLocation, Momentum, DamageType);
}

void AHumanNPC::execAttitudeTo(FFrame& Stack, RESULT_DECL)
{
	P_GET_OBJECT(AActor, Other);
	P_FINISH;

	*(DWORD*)Result = AttitudeTo(Other);
}