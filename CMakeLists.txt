cmake_minimum_required(VERSION 3.10)

# Project name
project(cmproj VERSION 0.1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Have cmake create a compile database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Static analysis done by CPP Check
add_custom_target(cppcheck-analysis 
        COMMAND cppcheck --template=gcc -i/usr/src/googletest --project=compile_commands.json)

# Compile options
# TODO: Add more!
add_compile_options("-Wall" "-Wextra" "-Wuninitialized" "-pedantic" "-Werror")

# Add Internal Component
add_subdirectory(mainCmp)
add_subdirectory(secCmp)
