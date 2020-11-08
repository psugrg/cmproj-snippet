##
# This is the CMakeList.txt file containing the test example configuration 
# based on Google Test framework

cmake_minimum_required(VERSION 3.16)

# Enable support for Gootle Test framework
find_package(GTest)

# Test project name
project(secCmp_test)

# Add googletest subdirectory
add_subdirectory(/usr/src/googletest ./googletest)

# Create test executable
add_executable(${PROJECT_NAME}
    test.cpp)

# Link required libraries
target_link_libraries(${PROJECT_NAME} secCmp gtest gtest_main)

# Add tests to CTest
gtest_discover_tests(${PROJECT_NAME})