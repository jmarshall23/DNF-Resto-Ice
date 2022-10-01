project(GalaxyLib C ASM_MASM)

string(APPEND CMAKE_ASM_MASM_FLAGS " /Cp /Cx")

file(GLOB HEADERS *.h Hdr/*.h)
file(GLOB SOURCES *.c *.asm)

# Excluded Items
list(REMOVE_ITEM SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Sbs.asm
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

# Excluded Items
list(REMOVE_ITEM SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/eax.c
	${CMAKE_CURRENT_SOURCE_DIR}/HUFFDEC.C
)

add_library(GalaxyLib STATIC ${HEADERS} ${SOURCES})

target_include_directories(GalaxyLib PRIVATE Hdr)
