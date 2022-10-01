set(PROJECT_NAME UWeb)

set(Classes
    "../Classes/HelloWeb.uc"
    "../Classes/ImageServer.uc"
    "../Classes/UWeb.upkg"
    "../Classes/WebApplication.uc"
    "../Classes/WebConnection.uc"
    "../Classes/WebRequest.uc"
    "../Classes/WebResponse.uc"
    "../Classes/WebServer.uc"
)
source_group("Classes" FILES ${Classes})

set(Inc
    "UWebPrivate.h"
)
source_group("Inc" FILES ${Inc})

set(Src
    "UWeb.cpp"
    "WebServer.cpp"
)
source_group("Src" FILES ${Src})

set(ALL_FILES
    ${Classes}
    ${Inc}
    ${Src}
)

add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
	../../Engine/Inc
	../../Engine/Src
	../../Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
	"_UNICODE" "UNICODE"
    "UWEB_API=__declspec(dllexport)"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    UWEB_EXPORTS
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Engine
)