project(Render C CXX)

file(GLOB HEADERS Src/*.h)
file(GLOB SOURCES Src/*.cpp Src/*.c)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

add_library(Render STATIC ${HEADERS} ${SOURCES})

target_link_libraries(Render PRIVATE xcore)

target_compile_definitions(Render PRIVATE
    "_UNICODE" "UNICODE"
    "CORE_API=__declspec(dllexport)"
    "ENGINE_API=__declspec(dllexport)"
    "RENDER_API=__declspec(dllexport)"
    "WINDOW_API=__declspec(dllexport)"
    "WINDRV_API=__declspec(dllexport)"
    "IPDRV_API=__declspec(dllexport)"
)

target_include_directories(Render PUBLIC Src)
target_include_directories(Render PRIVATE
	Src
    ../WinDrv/Inc
    ../Window/Inc
    ../Engine/Inc
	../Engine/Src
	../IpDrv/Src
    ${CMAKE_CURRENT_SOURCE_DIR}
)