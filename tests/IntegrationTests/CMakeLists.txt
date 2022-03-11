cmake_minimum_required(VERSION 3.18)
project(IntegrationTests VERSION 1.0)

add_subdirectory(TI-0001)
add_subdirectory(TI-0002)
#add_subdirectory(threads)

#add_custom_target(${PROJECT_NAME})
#add_dependencies(${PROJECT_NAME} TI-0001)

add_custom_target(${PROJECT_NAME}.build)
add_dependencies(${PROJECT_NAME}.build TI-0001.build TI-0002.build)

add_custom_target(${PROJECT_NAME}.run)
add_dependencies(${PROJECT_NAME}.run TI-0001.run)