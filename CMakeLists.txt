cmake_minimum_required(VERSION 3.5)

project(sudoku CXX)

# This project implement various approaches to solve sudokus.
# Adding a generator might happen too.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


option(WITH_TEST "build unit tests" ON)
option(WITH_BENCHMARKS "build benchmarks" ON)

set(CMAKE_CXX_STANDARD 17)

# Source code for library and executables.
add_subdirectory("src/")

# Tests for all parts.
if (${WITH_TEST})
    enable_testing()
    add_subdirectory("${CMAKE_SOURCE_DIR}/lib/googletest/googletest")
    add_subdirectory("test/")
endif()

if (${WITH_BENCHMARKS})
    enable_testing()
    add_subdirectory("benchmark/")
endif()
