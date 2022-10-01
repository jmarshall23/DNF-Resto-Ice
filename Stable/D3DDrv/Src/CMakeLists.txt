project(D3DDrv CXX ASM_MASM)

add_library(D3DDrv SHARED Direct3D8.cpp)

target_compile_definitions(D3DDrv PRIVATE
    "_UNICODE" "UNICODE"
)

target_link_libraries(D3DDrv PRIVATE
    Engine
    legacy_stdio_definitions
)

target_include_directories(D3DDrv PRIVATE
    ../../Core/Inc
    ../../Engine/Inc
    ../../Render/Inc
)