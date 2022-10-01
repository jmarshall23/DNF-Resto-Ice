set(PROJECT_NAME UWindow)

################################################################################
# Source groups
################################################################################
file(GLOB Classes ../Classes/*.uc)
source_group("Classes" FILES ${Sources})

set(ALL_FILES
    ${Classes}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})