project(MeshEd CXX)

file(GLOB Sources *.cpp)
source_group("Source Files" FILES ${Sources})
file(GLOB Headers *.h)
source_group("Header Files" FILES ${Headers})
file(GLOB Resources Res/*.bmp Res/*.gba Res/*.rc Res/*.h)
source_group("Resource Files" FILES ${Resources})

add_executable(MeshEd WIN32 ${Sources})

target_link_libraries(MeshEd PRIVATE
    xcore
    xcore_winapp
    comctl32
    dxguid
    dinput8
    winmm
)

target_compile_definitions(MeshEd PRIVATE
    KRN_DLL
)