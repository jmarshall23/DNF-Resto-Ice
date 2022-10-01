#!/bin/bash

>DukeEDLog.log
echo Starting DukeED...

cd `dirname $0`
BASEPATH=`pwd`
GAME_ROOT=%BASEPATH%/Stable

# ---------------------

cd "%GAME_ROOT%/System"

mv d3d8.dll d3d8_disabled.dll
wine DukeEd.exe
mv d3d8_disabled.dll d3d8.dll

# ---------------------