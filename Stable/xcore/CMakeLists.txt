project(xcore CXX ASM_NASM)

# TODO
# flagdata.cpp is supposed to be a generated source file,
# alongside the memoff.inc assembly include. Should try
# porting this from the original makefile at some point.
set(Header_Files
    "filex.h"
    "winalloc.h"
    "xclass.h"
    "xcore.h"
    "xipc.h"
    "xstream.h"
    "xstring.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
	"list.cpp"
	"file.cpp"
	"find.cpp"
	"malloc.asm"
	"winalloc.cpp"
	"dll.cpp"
	"error.cpp"
	"global.cpp"
	"printf.cpp"
	"stream.cpp"
	"string.cpp"
	"stuff.cpp"
#	"stuff.asm"
	"win.cpp"
	"winfile.cpp"
	"winmem.cpp"
	"xmisc.cpp"
	"flagdata.cpp"
	"stdcore.cpp"
	"xcore.def"
#    "gendata.cpp"
#    "genmem.cpp"
#    "ipc.cpp"
#    "stat.cpp"
)
source_group("Source Files" FILES ${Source_Files})

add_library(xcore SHARED
	${Header_Files}
	${Source_Files}
)

# The assembly files in xcore need to be assembled using NASM, rather than MASM.
set_source_files_properties(malloc.asm stuff.asm PROPERTIES LANGUAGE ASM_NASM)

target_compile_definitions(xcore PRIVATE XCORE_LIBRARY)
target_include_directories(xcore PUBLIC ${CMAKE_SOURCE_DIR}/Core/Inc ${CMAKE_CURRENT_SOURCE_DIR})

add_library(xcore_winapp STATIC winapp.cpp xwnd.cpp)
target_compile_definitions(xcore_winapp PRIVATE XCORE_PURE)
target_include_directories(xcore_winapp PRIVATE ${CMAKE_SOURCE_DIR}/Core/Inc ${CMAKE_CURRENT_SOURCE_DIR})

add_library(xcore_conapp STATIC conapp.cpp)
target_compile_definitions(xcore_conapp PRIVATE XCORE_PURE)
target_include_directories(xcore_conapp PRIVATE ${CMAKE_SOURCE_DIR}/Core/Inc ${CMAKE_CURRENT_SOURCE_DIR})