# WIP -- re-separate Core, Render, Window, WinDrv, IpDrv into their own projects
project(Engine C CXX)

file(GLOB HEADERS ../Inc/*.h)
file(GLOB SOURCES *.cpp *.c)
file(GLOB CLASSES ../Classes/*.uc)
file(GLOB RESOURCES Res/*.rc  Res/*.h  Res/*.ico  Res/*.bmp)

# Excluded Items
list(REMOVE_ITEM SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/AGeoWater.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SAPI.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/UnTerrain.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/UnRenderResource.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/UnStaticMesh.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/UnController.cpp
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("Resource Files" FILES ${RESOURCES})
source_group("UnrealScript Files" FILES ${CLASSES})

add_library(Engine SHARED ${HEADERS} ${SOURCES} ${RESOURCES} ${CLASSES})

target_link_options(Engine PRIVATE
    "/NODEFAULTLIB:LIBC"
)

target_link_libraries(Engine PRIVATE
    Cannibal
    Core
    xcore
    IpDrv
    Render
    Window
    WinDrv
    spchwrap
    comctl32
    dinput8
    dxguid
    winmm 
    s3tc
)

target_compile_definitions(Engine PRIVATE
    "_UNICODE" "UNICODE"
    "CORE_API=__declspec(dllexport)"
    "ENGINE_API=__declspec(dllexport)"
    "RENDER_API=__declspec(dllexport)"
    "WINDOW_API=__declspec(dllexport)"
    "WINDRV_API=__declspec(dllexport)"
    "IPDRV_API=__declspec(dllexport)"
)

target_include_directories(Engine PRIVATE
	../../Core/Inc
    ../../IpDrv/Src
    ../../IpDrv/Inc
    ../../WinDrv/Inc
    ../../Window/Inc
    ../../Engine/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}
)
