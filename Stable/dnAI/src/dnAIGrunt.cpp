/*=============================================================================
	dnAIGrunt.cpp
=============================================================================*/
#include <Engine.h>

#include "dnAIClasses.h"

IMPLEMENT_CLASS(AGrunt)

void AGrunt::execEstablishCover(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;

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
					CurrentCoverSpot = (ACoverSpot *)TestActor;
					CurrentCoverSpot->bOccupied = true;
					break;
				}
			}
		}
	}
}