set(PROJECT_NAME GlideDrv)

set(Src
    "UnGlide.cpp"
)
source_group("Src" FILES ${Src})

set(ALL_FILES
    ${Src}
)

add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
	../../xcore
	../../Cannibal
	../../Core/Inc
    ../../Engine/Inc
    ../../Engine/Src
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    UNICODE _UNICODE
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glide2x
    Engine
    xcore
)