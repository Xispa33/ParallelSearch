cmake_minimum_required(VERSION 3.0)
project(IntegrationTests VERSION 1.0)

add_subdirectory(TI-0001)
add_subdirectory(TI-0002)
add_subdirectory(TI-0003)

add_custom_target(${PROJECT_NAME}.build)
add_dependencies(${PROJECT_NAME}.build TI-0001.build TI-0002.build TI-0003.build engine)

add_custom_target(${PROJECT_NAME}.run)
add_dependencies(${PROJECT_NAME}.run TI-0001.run TI-0003.run)