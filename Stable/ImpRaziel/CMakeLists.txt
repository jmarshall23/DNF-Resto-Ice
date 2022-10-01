project(ImpRaziel CXX)

add_library(ImpRaziel SHARED ImpRaziel.cpp)

target_include_directories(ImpRaziel PRIVATE Inc)

target_link_directories(ImpRaziel PRIVATE Lib)

target_link_libraries(ImpRaziel PRIVATE Cannibal xcore assimp-vc143-mt odbc32 odbccp32)

target_link_options(ImpRaziel PRIVATE 
	"/SAFESEH:NO"
)

target_compile_definitions(ImpRaziel PRIVATE KRN_DLL KRN_NOPLACEMENTNEW)

set_target_properties(ImpRaziel PROPERTIES SUFFIX ".p")
