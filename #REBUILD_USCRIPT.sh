#!/bin/bash

>RebuildUscripts.log

# I'm too lazy to remake this entire file
function goto
{
    label=$1
    cmd=$(sed -n "/$label:/{:a;n;p;ba};" $0 | grep -v ':$')
    eval "$cmd"
    exit
}

#SETLOCAL EnableDelayedExpansion

cd `dirname $0`
BASEPATH=`pwd`
GAME_ROOT=%BASEPATH%/Stable
CONFORM=0

# ---------------------

cd "%GAME_ROOT%/System"
echo.

# There's probably a cleaner way to do this, but... fuck it for now.
if [ $1 = -conform ]
then
	set CONFORM=1
	goto $BUILDALL
fi

if [ $1 = "" ]
then
	goto $BUILDALL
else
	echo Rebuilding specific .u packages:
	
	for %%x in (%*) do (
		if [%%~x]==[-conform] (
			echo Found -noconform flag
			set CONFORM=1
		) else (
			echo %%~x
			rm %%~x.u
		)
	)
	
	wine ucc make -nobind
	
	if [!CONFORM!]==[1] (
		for %%x in (%*) do (
			if [%%~x]==[-conform] (
				echo.
			) else (
				echo CONFORMING %%~x
				wine ucc conform %%~x.u "%BASEPATH%/Junk/conform_dummy.u"
			)
		)
	)
	
	goto $END
fi

:BUILDALL
echo Rebuilding all .u packages...
rm *.u
wine ucc make -nobind
	
if [!CONFORM!]==[1] (
	for %%f in (*.u) do (
		echo %%~nf
		wine ucc conform "%%~nf.u" "%BASEPATH%/Junk/conform_dummy.u"
	)
)	
goto $END
# -- END BUILDALL --

:END
@pause

cd "%BASEPATH%"

# ---------------------