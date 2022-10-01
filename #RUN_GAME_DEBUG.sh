#!/bin/bash

function pause(){
 read -s -n 1 -p "Press any key to continue . . ."
 echo ""
}

>RunningGame.log

echo Starting Game...

cd `dirname $0`
BASEPATH=`pwd`
GAME_ROOT=%BASEPATH%/Stable

# ---------------------

cd "%GAME_ROOT%/System"

if [[ -f "engine.u" ]]
then
	echo Engine.u missing! Rebuilding.
	cd "%BASEPATH%"
	sh ./#REBUILD_USCRIPT.sh
fi

if [[ -f "DukeForever.exe" ]]
then
	echo "Oops! Looks like you're missing DukeForever.exe, do a full build!"
	pause
	exit
fi

cd "%GAME_ROOT%/System"
wine DukeForever.exe -log

cd "%BASEPATH%"

# ---------------------