cmake_minimum_required(VERSION 3.12)
project(DragonTests C CXX)

file(GLOB_RECURSE INC_ALL FOLLOW_SYMLINKS "*.h" "*.hpp")
file(GLOB_RECURSE SRC_ALL FOLLOW_SYMLINKS "*.c" "*.cpp")

message(STATUS "SRC_ALL is ${SRC_ALL}")

include_directories(${CMAKE_CURRENT_LIST_DIR}/../src)
list(APPEND SRC_ALL ${CMAKE_CURRENT_LIST_DIR}/../src/common/lexical_analyzer/LexicalAnalyzer.cpp)

#add_definitions(-D_TEST_PWD=${CMAKE_CURRENT_LIST_DIR})

################################
# GTest
################################
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../../ExternalTools/googletest googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${SRC_ALL} ${INC_ALL} googletest)

message(STATUS "PROJECT_NAME is ${PROJECT_NAME}")

# Testing LexicalAnalyzer
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${PROJECT_NAME})