#!/bin/bash

>RebuildCmake.log
echo Rebuilding Sources...

cd `dirname $0`
BASEPATH=`pwd`
GAME_ROOT=%BASEPATH%/Stable

# ---------------------

cd "%GAME_ROOT%"

echo .
echo Rebuilding the code:
echo TODO: Check if CMake projects are working.
cmake -G "Unix Makefiles" -B Build/Unix32

# ---------------------