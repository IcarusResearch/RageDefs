set(RAGEDEFS_SOURCES_DIR "${CMAKE_CURRENT_LIST_DIR}/src")

message(STATUS "Building RageDefs...")

file(GLOB_RECURSE RAGEDEFS_SOURCES
	"${RAGEDEFS_SOURCES_DIR}/Rage/**.h"
	"${RAGEDEFS_SOURCES_DIR}/Rage/**.cpp"
)

foreach(FILE ${RAGEDEFS_SOURCES})
  message(STATUS "Including file: ${FILE}")
endforeach()

add_library(RageDefs STATIC ${RAGEDEFS_SOURCES})
set_property(TARGET RageDefs PROPERTY CXX_STANDARD 23)
target_include_directories(RageDefs PUBLIC ${RAGEDEFS_SOURCES_DIR})
set_target_properties(RageDefs PROPERTIES LINKER_LANGUAGE CXX)
