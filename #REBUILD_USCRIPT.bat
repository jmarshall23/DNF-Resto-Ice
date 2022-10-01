@echo OFF
SETLOCAL EnableDelayedExpansion
SET BASEPATH=%~dp0.
SET GAME_ROOT=%BASEPATH%/Stable
SET CONFORM=0

:: ---------------------

cd /D "%GAME_ROOT%/System"
echo.

:: There's probably a cleaner way to do this, but... fuck it for now.
if [%1]==[-conform] (
	set CONFORM=1
	goto BUILDALL
)

if [%1]==[] (
	goto BUILDALL
) else (
	echo Rebuilding specific .u packages:
	
	for %%x in (%*) do (
		if [%%~x]==[-conform] (
			echo Found -noconform flag
			set CONFORM=1
		) else (
			echo %%~x
			del %%~x.u
		)
	)
	
	ucc make -nobind
	
	if [!CONFORM!]==[1] (
		for %%x in (%*) do (
			if [%%~x]==[-conform] (
				echo.
			) else (
				echo CONFORMING %%~x
				ucc conform %%~x.u "%BASEPATH%/Junk/conform_dummy.u"
			)
		)
	)
	
	goto END
)

:BUILDALL
echo Rebuilding all .u packages...
del *.u
ucc make -nobind
	
if [!CONFORM!]==[1] (
	for %%f in (*.u) do (
		echo %%~nf
		ucc conform "%%~nf.u" "%BASEPATH%/Junk/conform_dummy.u"
	)
)	
goto END
:: -- END BUILDALL --

:END
@pause

cd /D "%BASEPATH%"

:: ---------------------