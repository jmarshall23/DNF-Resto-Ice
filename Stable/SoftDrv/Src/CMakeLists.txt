project(SoftDrv CXX)

add_library(SoftDrv SHARED
    DrawPoly.cpp
    DrawSurf.cpp
    DrawTile.cpp
    Hit.cpp
    Line.h
    Line1.h
    Line2D.cpp
    SoftDrv.cpp
    SoftDrvPrivate.h
)

target_include_directories(SoftDrv PRIVATE
    ../../Core/Inc
    ../../Engine/Inc
    ../../Engine/Src
)

target_compile_definitions(SoftDrv PRIVATE
    "_UNICODE" "UNICODE"
)

target_link_libraries(SoftDrv PRIVATE
    Engine
)