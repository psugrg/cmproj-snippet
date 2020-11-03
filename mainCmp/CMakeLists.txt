##
# This is the CMakeLists.txt file containing the configuration of the mainCmp. 
# It includes the main() function and creates executable file.

cmake_minimum_required(VERSION 3.16)

# Project name (name of this component)
project(mainCmp)

# Add executable. The executable name is set in ${app_name} variable by the top level CMakeLists.txt
add_executable(${app_name} 
    src/cmproj.cpp
)

# Add include directories of this component
target_include_directories(${app_name} PUBLIC 
    ${PROJECT_SOURCE_DIR}/inc
)

# Generate Version header file
configure_file(inc/Version.h.in ${PROJECT_SOURCE_DIR}/inc/Version.h)

# Link required libraries
target_link_libraries(${app_name} PUBLIC secCmp)

# Install target configuration
install(TARGETS ${app_name} DESTINATION bin)