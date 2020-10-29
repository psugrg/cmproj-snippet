project(secCmp)

add_library(${PROJECT_NAME} src/Example.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

add_subdirectory(test)
