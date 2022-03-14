cmake_minimum_required(VERSION 3.0)
project(tests VERSION 1.0)

add_subdirectory(IntegrationTests)
add_subdirectory(UnitTests)

#add_custom_target(${PROJECT_NAME})
#add_dependencies(${PROJECT_NAME} UnitTests IntegrationTests)

add_custom_target(${PROJECT_NAME}.build)
add_dependencies(${PROJECT_NAME}.build UnitTests.build IntegrationTests.build)

add_custom_target(${PROJECT_NAME}.run)
add_dependencies(${PROJECT_NAME}.run UnitTests.run IntegrationTests.run)