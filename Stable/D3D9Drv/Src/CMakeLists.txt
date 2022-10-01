project(D3D9Drv CXX ASM_MASM)

add_library(D3D9Drv SHARED Direct3D9.cpp)

target_compile_definitions(D3D9Drv PRIVATE
    "_UNICODE" "UNICODE"
)

target_link_libraries(D3D9Drv PRIVATE
    Engine
    legacy_stdio_definitions
)

target_include_directories(D3D9Drv PRIVATE
    ../../Core/Inc
    ../../Engine/Inc
    ../../Render/Inc
)