cmake_minimum_required(VERSION 3.15)
project(dragon C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/lib)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(INC_ALL "Dragon.hpp")
set(SRC_ALL "main.cpp"
            "Dragon.cpp")

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(common/lexical_analyzer)
add_subdirectory(common/syntax_analyzer)
add_subdirectory(compiler)
add_subdirectory(interpreter)

add_executable(dragon ${SRC_ALL} ${SRC_ALL})
target_link_libraries(${PROJECT_NAME} lexical_analyzer syntax_analyzer)
