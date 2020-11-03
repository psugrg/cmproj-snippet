cmake_minimum_required(VERSION 3.16)

# Project name
project(cmproj VERSION 0.1.0)

# Set the name for the executable
set(app_name ${PROJECT_NAME})

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Have cmake create a compile database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Static analysis done by CPP Check
add_custom_target(cppcheck-analysis ALL
        COMMAND cppcheck 
                --template=gcc 
                -i/usr/src/googletest 
                --project=compile_commands.json)

# Compile options
# TODO: Add more!
add_compile_options("-Wall" "-Wextra" "-Wuninitialized")
# It's much better to add more flags especially -pedantic and -Werror
#add_compile_options("-Wall" "-Wextra" "-Wuninitialized" "-pedantic" "-Werror")

 
# Include CTest enables testing and Valgrind support for memory leak detection
include(CTest)

# Add Internal Component
add_subdirectory(mainCmp)
add_subdirectory(secCmp)
add_subdirectory(doc)
