cmake_minimum_required(VERSION 3.12)
project(lexical_analyzer C CXX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/lib)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

file(GLOB_RECURSE INC_ALL "*.h" "*.hpp")
file(GLOB_RECURSE SRC_ALL "*.c" "*.cpp")

include_directories(../)

add_library(${PROJECT_NAME} SHARED ${SRC_ALL} ${INC_ALL})
target_include_directories(${PROJECT_NAME} PUBLIC ${INC_ALL})