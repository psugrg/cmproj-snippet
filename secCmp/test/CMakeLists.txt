##
# This is the CMakeList.txt file containing the test example configuration 
# based on googletest framework

cmake_minimum_required(VERSION 3.10)

# Test project name
project(secCmp_test)

# Add googletest subdirectory
add_subdirectory(/usr/src/googletest ./googletest)

# Include CTest enables Valgrind support
include(CTest)

# Enable testing - self explanatory 
enable_testing()

# Create test executable
add_executable(${PROJECT_NAME}
    test.cpp)
   
# Link required libraries
target_link_libraries(${PROJECT_NAME} secCmp gtest gtest_main)

# Install target configuration (needed by CTest)
# install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Add tests to CTest
add_test(test_all ${PROJECT_NAME})