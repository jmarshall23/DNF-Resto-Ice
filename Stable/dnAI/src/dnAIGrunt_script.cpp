// dnAIGrunt_script.cpp
//

#include <Engine.h>

#include "dnAI.h"

void AGrunt::execCanFireAtEnemy(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;

	*(DWORD*)Result = CanFireAtEnemy();
}

void AGrunt::execPlayWeaponFire(FFrame& Stack, RESULT_DECL)
{
	P_GET_FLOAT(TweenTime);
	P_FINISH;

	PlayWeaponFire(TweenTime);
}

void AGrunt::execAutoFireWeapon(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;
	AutoFireWeapon();
}

void AGrunt::execSetAutoFireOn(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;
	SetAutoFireOn();
}

void AGrunt::execSetAutoFireOff(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;
	SetAutoFireOff();
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

void AGrunt::execCanUseWeapon(FFrame& Stack, RESULT_DECL)
{
	P_GET_OBJECT(AWeapon, w)
	P_FINISH;

	*(DWORD*)Result = CanUseWeapon(w);
}

void AGrunt::execFireWeapon(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;

	FireWeapon();
}