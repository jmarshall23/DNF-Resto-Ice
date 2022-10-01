#!/bin/bash

>RebuildSources.log

echo Rebuilding Sources...

cd `dirname $0`
BASEPATH=`pwd`
GAME_ROOT=%BASEPATH%/Stable

# ---------------------

cd "%GAME_ROOT%/System"

echo Building engine and editor packages.
rm engine.u
rm editor.u
wine ucc make -nobind

cd "%GAME_ROOT%"

echo .
echo Rebuilding the code:
echo Todo: Linux Build
#msdev Duke4.dsw /MAKE "BuildRelease - Win32 Release" /REBUILD

cd "%BASEPATH%"
echo .
sh ./#REBUILD_USCRIPT.sh

# ---------------------