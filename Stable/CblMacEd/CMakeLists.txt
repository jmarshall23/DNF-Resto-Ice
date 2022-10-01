project(CblMacEd CXX)

set(Sources
    "CblMacEd.cpp"
)
source_group("Sources" FILES ${Sources})

add_executable(CblMacEd WIN32 ${Sources})

target_link_libraries(CblMacEd PRIVATE
    Cannibal
)

target_compile_definitions(CblMacEd PRIVATE
    KRN_DLL
)