/*=============================================================================
	dnAIGrunt.cpp
=============================================================================*/
#include <Engine.h>

#include "dnAI.h"

IMPLEMENT_CLASS(AGrunt)

void AGrunt::EstablishCover(void)
{
	if (Enemy == nullptr)
		return;

	ULevel* CurrentLevel = GetLevel();
	INT MaxActors = CurrentLevel->Actors.Num();

	for (int i = 0; i < MaxActors; i++)
	{
		AActor* TestActor = CurrentLevel->Actors(i);
		if (TestActor != nullptr && TestActor->IsA(ACoverSpot::StaticClass()))
		{
			if (TestActor->Location.SizeSquared() < Square(CoverRadius + TestActor->CollisionRadius))
			{
				// Check to see if the enemy can see the new cover point, if we can then its not a good place to find cover. 
				if (!GetLevel()->Model->FastLineCheck(TestActor->Location, Enemy->Location))
				{
					CurrentCoverSpot = (ACoverSpot*)TestActor;
					CurrentCoverSpot->bOccupied = true;
					break;
				}
			}
		}
	}
}

void AGrunt::SetAutoFireOn(void)
{
	float i = 0.0f;

	if (Weapon == nullptr)
		return;

	if (Weapon->IsA(APistol::StaticClass()))
	{
		i = 0.5f;
	}
	else if (Weapon->IsA(AShotgun::StaticClass()))
	{
		i = 0.15f;
	}
	else if(Weapon->IsA(AM16::StaticClass()))
	{
		i = 0.15f;
	}

	SetCallbackTimer(i, true, TEXT("AutoFireWeapon"));
}

void AGrunt::execSetAutoFireOn(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;
	SetAutoFireOn();
}

void AGrunt::execEnablePainAnims(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;
	bAnimatePain = true;
}

void AGrunt::execEstablishCover(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;
	EstablishCover();
}