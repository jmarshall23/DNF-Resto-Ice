project(CannibalEdGlide CXX)

add_library(CannibalEdGlide SHARED
	font.cpp
	main.cpp
	vid_main.cpp
	vidtex.cpp
	vidglide.def
)

target_link_libraries(CannibalEdGlide PRIVATE
	xcore
	ximage
	msvcrt
	odbc32
	odbccp32
	fxmisc
	fxpci
	glide2x
	texus
)

target_link_options(CannibalEdGlide PRIVATE 
	"/NODEFAULTLIB:LIBC" 
	"/ALTERNATENAME:__imp_?xxx_bitch@@YAXPBD@Z=xxx_bitch"
	"/ALTERNATENAME:__imp_?xxx_throw@@YAXPBD@Z=xxx_throw"
)

target_include_directories(CannibalEdGlide PRIVATE "..")

if(MSVC)
    target_compile_definitions(CannibalEdGlide PRIVATE __MSC__)
endif()