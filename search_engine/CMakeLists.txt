cmake_minimum_required(VERSION 3.18)
project(search-engine VERSION 1.0)

add_subdirectory(engine)
#add_subdirectory(words_list)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} engine)
#add_dependencies(${PROJECT_NAME} words_list engine)
