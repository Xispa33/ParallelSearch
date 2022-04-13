cmake_minimum_required(VERSION 3.0)
project(TU-0001 VERSION 1.0)

set(TEST_NAME tu_1)

set(SRC test_1.cpp ${USR_FCT_SRC_DIR}/usr_fct.cpp)

include_directories(${USR_FCT_INC_DIR})

add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

#add_custom_target(${PROJECT_NAME}.run
#  COMMAND ${BUILD_UNIT_TESTS_DIR}/TU-0001/tu_1
#  DEPENDS ${PROJECT_NAME}.build
#)

add_executable(${TEST_NAME} ${SRC})

target_link_libraries(${TEST_NAME} PUBLIC
    gtest_main
)

target_special_setup(${PROJECT_NAME} ${TEST_NAME})