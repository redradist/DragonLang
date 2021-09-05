cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_COMPILER clang-12)
set(CMAKE_CXX_COMPILER clang++-12)

project(DragonLanguage)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
            TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

execute_process(COMMAND llvm-config-12 --cxxflags --ldflags --system-libs --libs core orcjit native
                OUTPUT_VARIABLE LLVM_CONFIG)

string(REGEX REPLACE "\r" " " LLVM_CONFIG "${LLVM_CONFIG}")
string(REGEX REPLACE "\n" " " LLVM_CONFIG "${LLVM_CONFIG}")
string(REGEX REPLACE "  " " " LLVM_CONFIG "${LLVM_CONFIG}")
string(REGEX REPLACE "  " " " LLVM_CONFIG "${LLVM_CONFIG}")
message(STATUS "LLVM_CONFIG is ${LLVM_CONFIG}")

add_compile_options(-I/usr/lib/llvm-12/include -std=c++14 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS)
add_link_options(-L/usr/lib/llvm-12/lib -lLLVM-12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type -Werror=return-stack-address -Werror=dangling -Werror=dangling-else -Werror=dangling-field -Werror=dangling-gsl -Werror=dangling-initializer-list")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_subdirectory(src)
#add_subdirectory(test)
