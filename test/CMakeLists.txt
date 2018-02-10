# Macros to define macros.
include(${CMAKE_SOURCE_DIR}/cmake/add_test.cmake)

add_unit_test(naive test_single_cell)
add_unit_test(naive test_sudoku)
