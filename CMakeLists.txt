cmake_minimum_required(VERSION 3.5)

project(sudoku)

# This project implement various approaches to solve sudokus.
# Adding a generator might happen too.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

enable_language(C++)

option(WITH_TEST "build unit tests" ON)
option(WITH_BENCHMARKS "build benchmarks" ON)


# Source code for library and executables.
add_subdirectory("src/")

# Tests for all parts.
if (${WITH_TEST})
    enable_testing()
    add_subdirectory("test/")
endif()

if (${WITH_BENCHMARKS})
    enable_testing()
    add_subdirectory("benchmark/")
endif()
