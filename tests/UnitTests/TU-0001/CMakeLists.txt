cmake_minimum_required(VERSION 3.8)
project(TU-0001 VERSION 1.0)

set(TEST_NAME tu_1)

set(SRC test_1.cpp ../../../usr_functions/src/usr_fct.cpp)
include_directories(../../../usr_functions/inc)

add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)
add_custom_target(${PROJECT_NAME}.run
  COMMAND /Users/brice/Desktop/Codes/ParallelSearch/build/tests/UnitTests/TU-0001/tu_1
  DEPENDS ${PROJECT_NAME}.build
)

add_executable(${TEST_NAME} ${SRC})

target_link_libraries(${TEST_NAME} PUBLIC
    gtest_main
)