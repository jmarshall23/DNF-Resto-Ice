set(PROJECT_NAME IpServer)

################################################################################
# Source groups
################################################################################
set(Classes
    "Classes/UdpServerQuery.uc"
    "Classes/UdpServerUplink.uc"
)
source_group("Classes" FILES ${Classes})

set(ALL_FILES
    ${Classes}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})

