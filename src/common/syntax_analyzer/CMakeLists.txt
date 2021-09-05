cmake_minimum_required(VERSION 3.12)
project(syntax_analyzer C CXX)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

file(GLOB_RECURSE INC_ALL "*.h" "*.hpp")
file(GLOB_RECURSE SRC_ALL "*.c" "*.cpp")

include_directories(../)
include_directories(/usr/include/llvm-10)
include_directories(/usr/include/llvm-c-10)

add_library(${PROJECT_NAME} SHARED ${SRC_ALL} ${INC_ALL})
target_include_directories(${PROJECT_NAME} PUBLIC ${INC_ALL})
target_link_libraries(${PROJECT_NAME} pthread lexical_analyzer)