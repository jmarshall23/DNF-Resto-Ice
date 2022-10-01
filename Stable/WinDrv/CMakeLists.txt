project(WinDrv C CXX)

file(GLOB HEADERS Inc/*.h)
file(GLOB SOURCES Src/*.cpp Src/*.c)
file(GLOB RESOURCES ../Engine/Src/Res/*.ico ../Engine/Src/Res/*.bmp ../Engine/Src/Res/*.cur Src/Res/*.rc Src/Res/*.h)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("Resource Files" FILES ${RESOURCES})

add_library(WinDrv STATIC ${SOURCES} ${RESOURCES})

target_link_libraries(WinDrv PRIVATE
    xcore
    dxguid
    DDraw
)

target_compile_definitions(WinDrv PRIVATE
    "_UNICODE" "UNICODE"
    "CORE_API=__declspec(dllexport)"
    "ENGINE_API=__declspec(dllexport)"
    "RENDER_API=__declspec(dllexport)"
    "WINDOW_API=__declspec(dllexport)"
    "WINDRV_API=__declspec(dllexport)"
    "IPDRV_API=__declspec(dllexport)"
)

target_include_directories(WinDrv PUBLIC Inc)
target_include_directories(WinDrv PRIVATE
	Src
	Inc
	../Window/Inc
	../Engine/Inc
	../Engine/Src
	../IpDrv/Src
	${CMAKE_CURRENT_SOURCE_DIR}
)