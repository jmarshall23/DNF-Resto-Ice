project(Launch C CXX)

set(no_group_source_files
    "../Engine/Src/Res/Logo.bmp"
)
source_group("" FILES ${no_group_source_files})

set(Fortify
    "../ThirdParty/Fortify/Src/Fortify.c"
    "../ThirdParty/Fortify/Src/Ufortify.hpp"
    "../ThirdParty/Fortify/Src/Zfortify.cpp"
    "../ThirdParty/Fortify/Src/Zfortify.hpp"
)
source_group("Fortify" FILES ${Fortify})

set(Res
    "../Engine/Src/Res/DukeForever.ico"
)
source_group("Res" FILES ${Res})

set(Src
    "Launch.cpp"
    "LaunchPrivate.h"
    "Res/LaunchRes.h"
	"Res/LaunchRes.rc"
)
source_group("Src" FILES ${Src})

add_executable(DukeForever WIN32
    ${no_group_source_files}
    ${Fortify}
    ${Res}
    ${Src}
)

target_include_directories(DukeForever PRIVATE
    ../Window/Inc
    ../Core/Inc
    ../Engine/Inc
)

target_compile_definitions(DukeForever PRIVATE
    "_UNICODE" "UNICODE"
)

target_link_libraries(DukeForever PRIVATE 
    Engine
    $<$<BOOL:${ENABLE_BUGSLAYER}>:BugslayerUtil>
    Comctl32
)