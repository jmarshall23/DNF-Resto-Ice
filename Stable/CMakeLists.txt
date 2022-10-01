cmake_minimum_required(VERSION 3.22)
project(Duke4)

# Output binaries to the System directory.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/System)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Compilation time options.
option(ENABLE_BUGSLAYER "Turn on BugSlayer implementation." ON)
option(ENABLE_64BITS "Enable x64 bits builds." OFF)

if((CMAKE_SYSTEM_NAME MATCHES "Windows"))
    # Visual Studio MSBuild
    if (MSVC)
        # Set NASM Paths
        set(CMAKE_ASM_NASM_COMPILER "${CMAKE_CURRENT_SOURCE_DIR}/bin/nasm/NASM.EXE")

        # Allow addressing more memory on a 64-bit host.
        add_link_options("/LARGEADDRESSAWARE")

        # Project is not compatible with data execution prevention.
        add_link_options("/NXCOMPAT:NO")

        # Project is not compatible with safe exception handlers.
        add_link_options("/SAFESEH:NO")

        # There are multiple locations in the source that invoke
        # va_start with a C++ reference. This is not portable, but
        # can be made to compile by disabling validation.
        add_compile_definitions(_CRT_NO_VA_START_VALIDATION)

        # 4-byte structure packing is required for compatibility.
        add_compile_options("/Zp4")
        add_compile_definitions(WINDOWS_IGNORE_PACKING_MISMATCH)

        # Microsoft extension that allows locals defined in a for
        # loop initializer to leak into the outside scope:
        #
        # for (int i = 0; i < N; i++);
        # for (i = 0; i < N; i++);
        # i = 0;
        #
        # Required by a significant portion of the source.
        add_compile_options("/Zc:forScope-")

        # The code doesn't like wchar_t being treated as a built-in type.
        add_compile_options("/Zc:wchar_t-")

        # Perform multi-process builds.
        add_compile_options("/MP")

        # Some project uses unsafe strinf functions across the project
        add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
		
		# Enable Bugslayer
		if (${ENABLE_BUGSLAYER})
			add_compile_definitions(BUGSLAYER_ENABLE)
		endif()

        # Suppres the next warnings.
        # Remove me once all of them are fixed.
        # C4661: 'XRcBase<CStrObj>::XRcBase(TYPE *)': no suitable definition provided for explicit template instantiation request
        # C4477: 'sprintf' : format string '%s' requires an argument of type 'char *', but variadic argument 1 has type 'CCorString'
        # A6004: procedure argument or local not referenced : EfxDesc
        # C4731: 'glxInit': frame pointer register 'ebx' modified by inline assembly code
        # C4667: 'FArchive &operator <<(FArchive &,TArray<TCHAR> &)': no function template defined that matches forced instantiation
        # C4838: conversion from 'EPolyFlagsEx' to 'DWORD' requires a narrowing conversion
        # C4091: 'typedef ': ignored on left of '<unnamed-enum-sfImage>' when no variable is declared
        # C4005: '_T': macro redefinition 
        # C4002: too many arguments for function-like macro invocation 'DECLARE_CLASS'
        # C4113: 'int (__cdecl *)(const char *const ,...)' differs in parameter lists from 'void (__cdecl *)(char *,...)'
        # LNK4017: EXETYPE stament not supported for the target platform; ignored
        add_definitions( "/wd4661 /wd4477 /wd6004 /wd4731 /wd4667 /wd4838 /wd4091 /wd4005 /wd4002 /wd4113 /wd4017" )

        # Include our VC6 libs
        link_directories(Libs/VC6)
    else()
        # Print a message that using the CMakeList for other compilers isn't ready yet.
        message(NOTICE: "The CMakeLists.txt isn't ready for other compilers isn't ready yet.")
    endif()
else() # GCC/clang/mingw
    # Print a message that using the CMakeList isn't ready for Linux Yet.
    message(NOTICE: "The CMakeLists.txt isn't ready for Linux Yet.")
endif()

# Thirdparty Implementations

# Freetype
include_directories(ThirdParty/Freetype/include)
# link_directories(ThirdParty/Freetype/Lib)

# Fortify
include_directories(ThirdParty/Fortify/Inc)

# S3 Texture Compression
include_directories(ThirdParty/S3tc/Inc)
link_directories(ThirdParty/S3tc/Lib)

if((CMAKE_SYSTEM_NAME MATCHES "Windows"))
    # DirectX 8
    include_directories(ThirdParty/DirectX8/Inc)
    link_directories(ThirdParty/DirectX8/Lib)
	
	# DirectX 9-11 (June 2010 SDK)
    add_compile_definitions(DIRECTINPUT_VERSION=0x0800) # This tells DirectX to use the older DX8 includes for direct input.
    include_directories(ThirdParty/DirectX2010/Inc)
    link_directories(ThirdParty/DirectX2010/Lib/x86)

    # Bugslayer
    if (${ENABLE_BUGSLAYER})
        include_directories(ThirdParty/Bugslayer/Inc)
        link_directories(ThirdParty/Bugslayer/Lib)
    endif()

    # Mrg
    include_directories(ThirdParty/Mrg/Inc)
    link_directories(ThirdParty/Mrg/Lib)

    # Glide
    include_directories(ThirdParty/Glide/Inc)
    link_directories(ThirdParty/Glide/Lib)

    # C3stk
    include_directories(ThirdParty/C3stk/Inc)
    link_directories(ThirdParty/C3stk/Lib)

    # Bink & Smack
    include_directories(ThirdParty/Bink/Inc)
    link_directories(ThirdParty/Bink/Lib)

    # Microsoft Speech SDK 4.0
    include_directories(ThirdParty/MicrosoftSpeechSDK40/Inc)
    link_directories(ThirdParty/MicrosoftSpeechSDK40/Lib)

    # Miles Sound System
    include_directories(ThirdParty/MilesSoundSystem/Inc)
    link_directories(ThirdParty/MilesSoundSystem/Lib)
endif()

# Projects
add_subdirectory(xcore)
add_subdirectory(Cannibal)
add_subdirectory(CannibalEditor)
add_subdirectory(CblMacEd)
add_subdirectory(MeshEd)
add_subdirectory(Core/Src)
add_subdirectory(Engine/Src)
add_subdirectory(IpDrv)
add_subdirectory(IpServer)
add_subdirectory(Render)
add_subdirectory(Window)
add_subdirectory(WinDrv)
add_subdirectory(Launch)
add_subdirectory(UCC/Src)
add_subdirectory(GalaxyLib)
add_subdirectory(Galaxy/Src)
add_subdirectory(Fire/Src)
add_subdirectory(SoftDrv/Src)
add_subdirectory(D3DDrv/Src)
add_subdirectory(D3D9Drv/Src)
add_subdirectory(Editor/Src)
add_subdirectory(DukeEd)
add_subdirectory(ximage)
add_subdirectory(CannibalEditor/vidglide)
add_subdirectory(MeshEd/vidd3d)
add_subdirectory(OpenGLDrv/Src)
add_subdirectory(UBrowser/Src)
add_subdirectory(UWeb/Src)
add_subdirectory(UWindow/Src)
add_subdirectory(Imp3DS)
add_subdirectory(ImpBP2)
#add_subdirectory(ImpC3S) # UNCOMMENT UNTIL WE FIND vg_lib.cPP FILE!
add_subdirectory(ImpGMA)
add_subdirectory(ImpLWO)
add_subdirectory(ImpMDX)
add_subdirectory(ImpRaziel)
#add_subdirectory(NullAudio/Src)