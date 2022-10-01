project(OpenGLDrv CXX ASM_MASM)

file(GLOB HEADERS ../Inc/*.h)
file(GLOB SOURCES *.cpp *.c)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

add_library(OpenGLDrv SHARED ${HEADERS} ${SOURCES})

target_compile_definitions(OpenGLDrv PRIVATE
    "_UNICODE" "UNICODE"
    WIN32_LEAN_AND_MEAN
    WIN32
    UTGLR_UT_BUILD
    UTGLR_DNF_BUILD
)
target_link_libraries(OpenGLDrv PRIVATE Engine legacy_stdio_definitions winmm)

target_link_options(OpenGLDrv PRIVATE
    "/SAFESEH:NO"
)

target_include_directories(OpenGLDrv PRIVATE
    ../../Core/Inc
    ../../Engine/Inc
    ../../Render/Inc
    ../Inc
    ${CMAKE_CURRENT_SOURCE_DIR}
)