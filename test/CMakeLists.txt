add_executable(test_single_slot.x naive/test_single_slot.cpp)
target_link_libraries(test_single_slot.x gtest_main
                                         ${GTEST_MAIN} 
                                         ${GTEST_LIBRARIES}
                                         pthread)
add_test(test_single_slot test_single_slot.x)
