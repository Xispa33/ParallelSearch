cmake_minimum_required(VERSION 3.18)
project(TI-0001 VERSION 1.0)

set(TEST_NAME ti_1)
set(SRC ti_1.cpp)

include_directories(../../../search_engine/engine/inc)

add_executable(${TEST_NAME} ${SRC})

add_custom_target(${PROJECT_NAME})
add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

add_custom_target(${PROJECT_NAME}.run
  COMMAND /Users/brice/Desktop/Codes/ParallelSearch/build/tests/IntegrationTests/TI-0001/ti_1
  DEPENDS ${PROJECT_NAME}.build
)

target_link_libraries(${TEST_NAME} PUBLIC
    libeng
)

#set_target_properties(${TEST_NAME} PROPERTIES 
#    SUFFIX .a
#)