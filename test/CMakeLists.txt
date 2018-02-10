add_executable(test_single_cell.x naive/test_single_cell.cpp)
target_include_directories(test_single_cell.x PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(test_single_cell.x naive_functions
                                         gtest_main
                                         ${GTEST_MAIN} 
                                         ${GTEST_LIBRARIES}
                                         pthread)
add_test(test_single_cell test_single_cell.x)
