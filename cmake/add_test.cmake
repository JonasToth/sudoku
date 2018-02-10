macro(add_unit_test component test_name)
    add_executable(${test_name}.x ${component}/${test_name})

    target_include_directories(${test_name}.x PRIVATE ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(${test_name}.x ${component}_functions
                                         gtest_main
                                         ${GTEST_MAIN}
                                         ${GTEST_LIBRARIES}
                                         pthread)
    add_test(${test_name} ${test_name}.x)
endmacro()
