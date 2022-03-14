cmake_minimum_required(VERSION 3.0)
project(search-engine VERSION 1.0)

add_subdirectory(engine)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} engine)
