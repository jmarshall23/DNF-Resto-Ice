project(Cannibal CXX ASM_MASM)

set(no_group_source_files
    "Cannibal.h"
)
source_group("" FILES ${no_group_source_files})

set(Files
    "FileBox.cpp"
    "FileBox.h"
    "FileMain.cpp"
    "FileMain.h"
)
source_group("Files" FILES ${Files})

set(Input
    "InDefs.h"
    "InMain.cpp"
    "InMain.h"
    "InWin.cpp"
    "InWin.h"
)
source_group("Input" FILES ${Input})

set(Kernel
    "CorMain.cpp"
    "CorMain.h"
    "Kernel.cpp"
    "Kernel.h"
    "KrnBuild.h"
    "KrnDefs.h"
    "KrnInc.h"
    "KrnTypes.h"
    "msg.asm"
    "StrMain.cpp"
    "StrMain.h"
)
source_group("Kernel" FILES ${Kernel})

set(Logging
    "LogMain.cpp"
    "LogMain.h"
)
source_group("Logging" FILES ${Logging})

set(Mathematics
    "MathFlt.h"
    "VecMain.h"
    "VecPrim.h"
)
source_group("Mathematics" FILES ${Mathematics})

set(Memory
    "MemMain.cpp"
    "MemMain.h"
)
source_group("Memory" FILES ${Memory})

set(Models__Model_Actors
    "MacEdit.cpp"
    "MacEdit.h"
    "MacMain.cpp"
    "MacMain.h"
)
source_group("Models\\Model Actors" FILES ${Models__Model_Actors})

set(Models__Model_Actors__Res
    "Res/CpjCpj.bmp"
    "Res/CpjFrm.bmp"
    "Res/CpjGeo.bmp"
    "Res/CpjLod.bmp"
    "Res/CpjMac.bmp"
    "Res/CpjSeq.bmp"
    "Res/CpjSkl.bmp"
    "Res/CpjSrf.bmp"
    "Res/FileClosed.bmp"
    "Res/FileOpen.bmp"
    "Res/MacEdit.h"
    "Res/MacEdit.rc"
)
source_group("Models\\Model Actors\\Res" FILES ${Models__Model_Actors__Res})

set(Models__Project_Files
    "CpjFmt.h"
    "CpjFrm.cpp"
    "CpjFrm.h"
    "CpjGeo.cpp"
    "CpjGeo.h"
    "CpjLod.cpp"
    "CpjLod.h"
    "CpjMac.cpp"
    "CpjMac.h"
    "CpjMain.cpp"
    "CpjMain.h"
    "CpjProj.cpp"
    "CpjProj.h"
    "CpjSeq.cpp"
    "CpjSeq.h"
    "CpjSkl.cpp"
    "CpjSkl.h"
    "CpjSrf.cpp"
    "CpjSrf.h"
)
source_group("Models\\Project Files" FILES ${Models__Project_Files})

set(Objects
    "MsgMain.cpp"
    "MsgMain.h"
    "ObjMain.cpp"
    "ObjMain.h"
)
source_group("Objects" FILES ${Objects})

set(Parsing
    "LexMain.cpp"
    "LexMain.h"
    "PrsMain.cpp"
    "PrsMain.h"
)
source_group("Parsing" FILES ${Parsing})

set(Platform
    "IpcMain.cpp"
    "IpcMain.h"
    "WinCtrl.cpp"
    "WinCtrl.h"
)
source_group("Platform" FILES ${Platform})

set(Plugins
    "PlgMain.cpp"
    "PlgMain.h"
)
source_group("Plugins" FILES ${Plugins})

set(Timing
    "TimeMain.cpp"
    "TimeMain.h"
)
source_group("Timing" FILES ${Timing})

add_library(Cannibal SHARED
    ${no_group_source_files}
    ${Files}
    ${Input}
    ${Kernel}
    ${Logging}
    ${Mathematics}
    ${Memory}
    ${Models__Model_Actors}
    ${Models__Model_Actors__Res}
    ${Models__Project_Files}
    ${Objects}
    ${Parsing}
    ${Platform}
    ${Plugins}
    ${Timing}
)

target_include_directories(Cannibal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(Cannibal PRIVATE
    CANNIBAL_EXPORTS
    KRN_EXPORTS
    KRN_DLL
    XCORE_PURE
)

target_link_directories(Cannibal PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(Cannibal PUBLIC
    xcore
    $<IF:$<CONFIG:Debug>,Mrgd,Mrg>
)

target_link_libraries(Cannibal PRIVATE
    comctl32
)