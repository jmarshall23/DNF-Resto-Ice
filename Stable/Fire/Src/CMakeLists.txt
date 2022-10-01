project(Fire CXX ASM_MASM)

file(GLOB CLASSES ../Classes/*.uc)

set(HEADERS
    "FractalPrivate.h"
)

set(SOURCES
    "UnFractal.cpp"
    "UnFire.asm"
    "UnFireP2.asm"
    "UnWater.asm"
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("UnrealScript Files" FILES ${CLASSES})

add_library(Fire SHARED
    ${HEADERS}
    ${SOURCES}
    ${CLASSES}
)

target_compile_definitions(Fire PRIVATE
    "_UNICODE" "UNICODE"
)

target_link_libraries(Fire PRIVATE
    Engine
)

target_include_directories(Fire PRIVATE
    ../../Core/Inc
    ../../Engine/Inc
)
