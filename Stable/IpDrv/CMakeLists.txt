project(IpDrv C CXX)

file(GLOB HEADERS Inc/*.h)
file(GLOB SOURCES Src/*.cpp Src/*.c)
file(GLOB CLASSES Classes/*.uc)

# Excluded Items
list(REMOVE_ITEM SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Src/IpDrv.cpp
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("UnrealScript Files" FILES ${CLASSES})

add_library(IpDrv STATIC ${HEADERS} ${SOURCES} ${CLASSES})

target_link_libraries(IpDrv PRIVATE xcore)

target_compile_definitions(IpDrv PRIVATE
    "_UNICODE" "UNICODE"
    "CORE_API=__declspec(dllexport)"
    "ENGINE_API=__declspec(dllexport)"
    "RENDER_API=__declspec(dllexport)"
    "WINDOW_API=__declspec(dllexport)"
    "WINDRV_API=__declspec(dllexport)"
    "IPDRV_API=__declspec(dllexport)"
)

target_include_directories(IpDrv PUBLIC Inc)
target_include_directories(IpDrv PRIVATE
	Src
	Inc
    ../WinDrv/Inc
    ../Window/Inc
    ../Engine/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}
)
