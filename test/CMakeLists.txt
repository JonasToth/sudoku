add_executable(test_single_cell.x naive/test_single_cell.cpp)
target_link_libraries(test_single_cell.x gtest_main
                                         ${GTEST_MAIN} 
                                         ${GTEST_LIBRARIES}
                                         pthread)
add_test(test_single_cell test_single_cell.x)
