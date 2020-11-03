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

# Install rules
# NOTE: This is a static library hence no need of installing it. Let's install it anyhow as an example.
install(TARGETS ${PROJ_NAME} DESTINATION lib)
install(FILES inc/Example.hpp DESTINATION include)
