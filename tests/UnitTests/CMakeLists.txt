cmake_minimum_required(VERSION 3.0)
project(UnitTests VERSION 1.0)

add_subdirectory(googletest)
add_subdirectory(TU-0001)
add_subdirectory(TU-0002)
add_subdirectory(TU-0003)
add_subdirectory(TU-0004)

#add_custom_target(${PROJECT_NAME})
#add_dependencies(${PROJECT_NAME} TU-0001 TU-0002)

add_custom_target(${PROJECT_NAME}.build)
add_dependencies(${PROJECT_NAME}.build 
    TU-0001.build
    TU-0002.build
    TU-0003.build
    TU-0004.build
)

add_custom_target(${PROJECT_NAME}.run)
add_dependencies(${PROJECT_NAME}.run 
    TU-0001.run
    TU-0002.run
    TU-0003.run
    TU-0004.run
)