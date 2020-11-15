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

# Compile options
add_compile_options("-Wall" "-Wextra" "-Wuninitialized")
# It's much better to add more flags especially -pedantic and -Werror
#add_compile_options("-Wall" "-Wextra" "-Wuninitialized" "-pedantic" "-Werror")

# Add new build types
message("* Adding build types...")
SET(CMAKE_CXX_FLAGS_COVERAGE
    "${GCC_DEBUG_FLAGS} -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE )
SET(CMAKE_C_FLAGS_COVERAGE
    "${GCC_DEBUG_FLAGS} -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE )
SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE )
SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE )
MARK_AS_ADVANCED(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE )

IF(NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE Debug
       CACHE STRING "Choose the type of build : None Debug Release RelWithDebInfo MinSizeRel Coverage."
       FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)
message("* Current build type is : ${CMAKE_BUILD_TYPE}")

# Include CTest enables testing and Valgrind support for memory leak detection
include(CTest)

# Add Internal Component
add_subdirectory(mainCmp)
add_subdirectory(secCmp)
add_subdirectory(doc)

# Code Coverage target
add_custom_target(coverage  
        COMMAND gcovr 
        -r ${CMAKE_CURRENT_SOURCE_DIR}
        ${coverage_files_dir}
        VERBATIM)

# Static analysis done by CPP Check
# (This will ignore the /usr/src/googletest directory)
add_custom_target(scheck ALL
        COMMAND cppcheck 
                --template=gcc 
                -i/usr/src/googletest 
                --project=compile_commands.json
        VERBATIM)

install(FILES cmproj.desktop DESTINATION share/applications)
install(FILES twotone_pest_control_rodent_black_18dp.png DESTINATION share/pixmaps)