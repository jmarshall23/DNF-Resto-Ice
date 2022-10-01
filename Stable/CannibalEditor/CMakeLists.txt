project(CannibalEditor CXX)

set(Header_Files__Overlay_Headers
    "ovl_cc.h"
    "ovl_defs.h"
    "ovl_frm.h"
    "ovl_mdl.h"
    "ovl_seq.h"
    "ovl_skin.h"
    "ovl_work.h"
)
source_group("Header Files\\Overlay Headers" FILES ${Header_Files__Overlay_Headers})

set(Header_Files__System_Headers
	"cam_man.h"
	"cbl_defs.h"
	"con_man.h"
	"file_imp.h"
	"in_main.h"
	"in_win.h"
	"math_vec.h"
	"mdx_man.h"
	"ovl_man.h"
	"sys_main.h"
	"sys_win.h"
	"vcr_man.h"
	"vid_main.h"
)
source_group("Header Files\\System Headers" FILES ${Header_Files__System_Headers})

set(Resource_Files
	"Res/CannibalEditor.ico"
	"Res/CannibalEditor.h"
    "Res/CannibalEditor.rc"
)
source_group("Resource Files" FILES ${Resource_Files})

set(Source_Files__Overlays
    "ovl_cc.cpp"
    "ovl_defs.cpp"
    "ovl_frm.cpp"
    "ovl_mdl.cpp"
    "ovl_seq.cpp"
    "ovl_skin.cpp"
    "ovl_work.cpp"
)
source_group("Source Files\\Overlays" FILES ${Source_Files__Overlays})

set(Source_Files__System
    "cam_man.cpp"
    "con_man.cpp"
    "file_imp.cpp"
    "in_main.cpp"
    "in_win.cpp"
    "math_vec.cpp"
    "mdx_man.cpp"
    "ovl_man.cpp"
    "sys_main.cpp"
    "sys_win.cpp"
    "vcr_man.cpp"
    "vid_main.cpp"
)
source_group("Source Files\\System" FILES ${Source_Files__System})

add_executable(CannibalEd WIN32
	${Header_Files__Overlay_Headers}
	${Header_Files__System_Headers}
	${Resource_Files}
	${Source_Files__Overlays}
	${Source_Files__System}
)

target_compile_definitions(CannibalEd PRIVATE
    CANNIBAL_TOOL
    XCORE_PURE
)

target_link_libraries(CannibalEd PRIVATE
    xcore
    comctl32
    dxguid
    dinput8
    winmm
)