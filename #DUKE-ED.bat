@echo OFF
echo Starting DukeED...

SET BASEPATH=%~dp0.
SET GAME_ROOT=%BASEPATH%/Stable

REM ---------------------

cd /D "%GAME_ROOT%/System"

rename d3d8.dll d3d8_disabled.dll
start /wait DukeEd.exe
rename d3d8_disabled.dll d3d8.dll

REM ---------------------