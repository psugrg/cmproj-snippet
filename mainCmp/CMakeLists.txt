project(mainCmp)

# add executable
add_executable(${PROJECT_NAME} 
    src/cmproj.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/inc
)

configure_file(inc/Version.h.in ${PROJECT_SOURCE_DIR}/inc/Version.h)

target_link_libraries(${PROJECT_NAME} PUBLIC secCmp)