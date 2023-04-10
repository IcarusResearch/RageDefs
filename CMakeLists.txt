cmake_minimum_required(VERSION 3.20)
project(RageDefs CXX)
add_definitions(-DUNICODE -D_UNICODE)
set(RAGEDEF_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

message(STATUS "Building RageDefs..")
file(GLOB_RECURSE SRC_RageDefs
    "${CMAKE_CURRENT_LIST_DIR}/**.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/**.h"
)

add_library(RageDefs STATIC "${SRC_RageDefs}")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET RageDefs PROPERTY CXX_STANDARD 23)
set_target_properties(RageDefs PROPERTIES LINKER_LANGUAGE CXX)
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} PREFIX RageDefs FILES ${SRC_RageDefs})
target_include_directories(RageDefs PRIVATE 
    "${CMAKE_CURRENT_LIST_DIR}"
)
