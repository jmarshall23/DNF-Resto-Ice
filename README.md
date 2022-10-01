# Welcome to Duke Nukem Forever 2001 Leak Repository #

This repository has multiple aims:

- Reduce fragmentation by combining the various efforts of the Duke Community to fix and improve the game.
- Assembling documentation of the game, its sources, unused content, and share general knowledge of DNF and the Unreal Engine.
- Getting DNF compiling on modern toolsets, such as Visual Studio Community 2022

# The Content #

As you might have noticed, this version has different folders compared to its original leak, that can be found at https://archive.org/details/duke-nukem-forever-2001-leak . 

The Stable folder was originally the "October 26" folder, that has been patched with the MegaPatch and the dnGame.u file re-enabled inside System thanks to Zombie (you can find the thread here https://forums.duke4.net/topic/12013-leaked-duke-nukem-forever-2001/ ).

# How To Run It #

After cloning the repo, you **must** run `#REBUILD_USCRIPT.bat` at least once to compile the base game .u files.
This is by design, as it made no sense to store the `.u` binaries.

Afterwards, to run the game, you can either run `#RUN_GAME.bat` or simply find DukeForever.exe in Stable/System.

`#FULLBUILD.bat` is a development convenience tool that runs `#REBUILD_USCRIPT.bat` to compile .u files, then automatically start the game.

# Read this for VS 2022! #
If you wish to build the game using the native drivers through Visual Studio 2022 and enjoy the fixes that way, you must have the following installed:
-Visual Studio 2022 (w/ latest v143 build tools for x86/x64)
-cmake

Assuming that both are installed and cmake has been added to your PATH environment variables, you can run `#REBUILD_CMAKE.bat` to generate the compiled .sln and project files for the Visual Studio 2022 version. These can be found in `.\Stable\Build\Win32`

With the project files generated, you're now free to open the `.sln` and tinker as needed! If you wish to just play the game, it is recommended you switch your build configuration to `Release` and perform an `ALL-BUILD` through VS2022.

You can change the game's resolution in DukeForever.ini under Stable/Players. There is a launcher being made to streamline this process.

# Contributing #
Check the wiki.

## Note on line endings ##
Some files in the project require crlf line endings.

If you're on Windows, this is probably the default and you don't need to do anything.
If you're using Linux/Mac, you will need to turn on git autocrlf.

You can do so by setting `core.autocrlf = true` in the git config.
You can add it inside the local `.git/config` in your repository.


```
[core]
autocrlf = true
```

If you already checked out the files, you will need to check them out again.
One way is to delete all files in your working tree, and check out everything again
with `git checkout .`.

## Note for anyone who wants to modify textures and/or sounds ##
DukeEd.exe only partially loads .dtx and .dfx files on launch, causing you to lose half your textures/sounds if you save them in this state! Make sure to go to File -> Open -> yourpackage before making modifications to any texture or sound packages!

# Authors #

- StrikerTheHedgefox: Repo Admin, Lead Programmer
- Xinerki: Repo Maintainer, Lead Programmer
- Zombie: Repo Admin, Programmer
- Green: Repo Admin
- Ozymandias81: Created repo I forked this from, and wrote most of this README.MD.
- BFG9000: Other minor wrapper attempts (D3D8-9)
- meowsandstuff: Lead Audio Director, Music Production, Programmer, Voice Actor, Level Design, Script/Story
- Ch0wW: Programming
- hogsy: Programming

# Public Mirror #
- https://gitlab.com/DNF-2001-Restoration-Team/dnf2001r-periodic-mirror