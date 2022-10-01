set(PROJECT_NAME ImpBP2)

set(Sources
    "ImpBP2.cpp"
)
source_group("Source Files" FILES ${Sources})

set(ALL_FILES
    ${Sources}
)

add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME} SUFFIX ".p")

target_include_directories(${PROJECT_NAME} PRIVATE
	../../xcore
	../../Cannibal
	../../Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
	IMPBP2_EXPORTS
	KRN_DLL
	_MBCS
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	Cannibal
	xcore
	odbc32
	odbccp32
)