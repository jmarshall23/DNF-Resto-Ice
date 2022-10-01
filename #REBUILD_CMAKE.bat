@echo OFF
echo Rebuilding Sources...

SET BASEPATH=%~dp0.
SET GAME_ROOT=%BASEPATH%/Stable

REM ---------------------

cd /D "%GAME_ROOT%"

echo .
echo Rebuilding the code:
echo TODO: Check if CMake projects are working.
cmake -G "Visual Studio 17 2022" -A Win32 -B Build/Win32

REM ---------------------