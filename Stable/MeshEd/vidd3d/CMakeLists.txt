project(MeshEdD3D CXX)

add_library(MeshEdD3D SHARED 
	dev.cpp
	font.cpp
	main.cpp
	stdd3d.cpp
	stdd3d.h
	tex.cpp
	vbuffer.cpp
	vidd3d.h
	vidif.cpp
	vidd3d.def
)

target_link_libraries(MeshEdD3D PRIVATE xcore_winapp xcore ximage dxguid dinput8 d3d8 d3dx8 legacy_stdio_definitions)

target_link_options(MeshEdD3D PRIVATE "/NODEFAULTLIB:LIBC")

target_link_directories(MeshEdD3D PRIVATE Lib)

target_include_directories(MeshEdD3D PRIVATE 
	../Core/Inc
	../xcore
	".."
)

if(MSVC)
    target_compile_definitions(MeshEdD3D PRIVATE __MSC__ XCORE_PURE)
endif()
