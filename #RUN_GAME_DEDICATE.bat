@echo OFF
title Shades OS Dedicate Server
echo Starting Dedicate Server Game...

SET BASEPATH=%~dp0.
SET GAME_ROOT=%BASEPATH%/Stable

REM ---------------------

cd /D "%GAME_ROOT%/System"

if not exist engine.u (
	echo Engine.u missing! Rebuilding.
	cd /D "%BASEPATH%"
	call #REBUILD_USCRIPT.bat
)

if not exist DukeForever.exe (
	echo Oops! Looks like you're missing DukeForever.exe, do a full build!
	pause
	exit
)

cd /D "%GAME_ROOT%/System"
start DukeForever.exe -log
UCC server Dm-BellTollRemix.dnf?GameType=dnGame.dnDeathmatchGame -ini=DukeForever.ini -userini=user.ini port=7777

cd /D "%BASEPATH%"

REM ---------------------