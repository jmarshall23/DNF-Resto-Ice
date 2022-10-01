#!/bin/bash

>FullBuild.log

echo Building the game...
sh ./#REBUILD_USCRIPT.sh

echo Launching the game...
sh ./#RUN_GAME_DEBUG.sh

cd ..
cd ..