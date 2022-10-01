project(ximage CXX)

add_library(ximage SHARED
	bmp.cpp
	dll.cpp
	image.cpp
	tga.cpp
	ximage.def
)

target_include_directories(ximage PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	../Core/Inc
	../xcore
)

target_link_libraries(ximage PRIVATE
	xcore
)

target_compile_definitions(ximage PRIVATE
	XCORE_PURE
	XIMAGE_LIBRARY
)