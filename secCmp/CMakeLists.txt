##
# This is the CMakeLists.txt file containing the configuration of the secCmp. 
# It is a library component included ny the mainCmp.

# The name of the project (library)
project(secCmp)

# Creates a library 
add_library(${PROJECT_NAME} src/Example.cpp)

# Add include directories to the project
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

# Add Tests
add_subdirectory(test)
