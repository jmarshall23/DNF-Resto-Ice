project(Galaxy)

add_library(Galaxy SHARED
    A3D.cpp A3D.h
    ../Hdr/GALAXY.H
    ia3dapi.h
    UnGalaxy.cpp
)

target_link_options(Galaxy PRIVATE
    "/NODEFAULTLIB:LIBC"
)

target_link_libraries(Galaxy PRIVATE Engine
    GalaxyLib
    dxguid
    mss32
    legacy_stdio_definitions
)

target_compile_definitions(Galaxy PRIVATE 
    "_UNICODE" "UNICODE"
)

target_include_directories(Galaxy PRIVATE
    ../Hdr
    ../../Render/Src
    ../../Engine/Inc
    ../../Core/Inc
)