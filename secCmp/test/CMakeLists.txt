cmake_minimum_required(VERSION 3.10)

project(secCmp_test)

add_subdirectory(/usr/src/googletest ./googletest)

enable_testing()

add_executable(secCmp_unitTests
    test.cpp)
    
target_link_libraries(secCmp_unitTests secCmp gtest gtest_main)

add_test(test_all secCmp_unitTest)