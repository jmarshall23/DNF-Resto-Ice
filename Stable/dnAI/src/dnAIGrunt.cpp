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

void AGrunt::PlayWeaponFire(float TweenTime)
{
	if (TweenTime == 0.0)
		TweenTime = 0.1;

	if (Weapon == nullptr)
		return;

	if (Weapon->IsA(AM16::StaticClass()))
		eventPlayAnimEvent(TEXT("T_M16Fire"), 6.0, TweenTime, false, false, true);
	else if (Weapon->IsA(AShotgun::StaticClass()))
		eventPlayAnimEvent(TEXT("T_SGFire"), 0.0f, TweenTime, false, false, false);
	else if (Weapon->IsA(APistol::StaticClass()))
		eventPlayAnimEvent(TEXT("T_Pistol2HandFire"), 0.0f, TweenTime, false, false, true);
}

void AGrunt::AutoFireWeapon(void)
{
	if (Weapon == NULL)
		return;

	AdnWeapon* dnWeapon = (AdnWeapon*)Weapon;

	if (dnWeapon->eventGottaReload())
	{		
		dnWeapon->AmmoType->eventAddAmmo(9999, 0);

		if (dnWeapon->IsA(APistol::StaticClass()))
		{
			dnWeapon->AmmoLoaded = 8;
		}
		else
		{
			dnWeapon->AmmoLoaded = 50;
		}
	}

	bFire = true;
	dnWeapon->FireAnim.AnimTween = 0.1f;
	PlayWeaponFire();
	Weapon->eventFireNative();
}

void AGrunt::SetAutoFireOff(void)
{
	EndCallbackTimer(TEXT("AutoFireWeapon"));
}

bool AGrunt::CanFireAtEnemy(void)
{
	FVector HitLocation, HitNormal, X, Y, Z, projStart;
	AActor *HitActor;

	if (Weapon == nullptr)
		return false;

	if (Enemy == nullptr)
		return false;

	GetAxes(Rotation, X, Y, Z);

	projStart = Location + Weapon->eventCalcDrawOffset() + Weapon->FireOffset.X * X + 1.2 * Weapon->FireOffset.Y * Y + Weapon->FireOffset.Z * Z;

	if (Weapon->bInstantHit)
		HitActor = Trace(Enemy->Location + Enemy->CollisionHeight * FVector(0, 0, 0.7), projStart, true, &HitLocation, &HitNormal);
	else
		HitActor = Trace(projStart + Min<FLOAT>(280, VSize(Enemy->Location - Location)) * (Enemy->Location + Enemy->CollisionHeight * FVector(0, 0, 0.7) - Location).SafeNormal(), projStart, true, &HitLocation, &HitNormal);

	if (HitActor == Enemy || (HitActor != nullptr && HitActor->IsA(AEDFshield::StaticClass())) || (HitActor != nullptr && HitActor->IsA(AdnDecoration::StaticClass()) && Cast<AdnDecoration>(HitActor)->HealthPrefab != HEALTH_NeverBreak))
		return true;

	if ((Cast<APawn>(HitActor) != nullptr) && (AttitudeTo(HitActor) < ATTITUDE_Ignore))
		return false;

	if (HitActor != nullptr && HitActor->bBlockActors)
		return false;

	return true;
}

bool AGrunt::CanUseWeapon(AWeapon *w)
{
	bool bNoAmmo, bNoAltAmmo;

	if (w == nullptr)
	{
		return(false);
	}

	if (Weapon != nullptr)
	{
		if (bArmless && !Weapon->IsA(APistol::StaticClass()))
			return false;
	}

	bNoAmmo = (w->AmmoName != nullptr);
	if (bNoAmmo && (w->AmmoType->eventGetModeAmmoEvent() > 0))
		bNoAmmo = false;
	if (bNoAmmo)// && bNoAltAmmo)
		return(false);
	return(true);
}