cmake_minimum_required(VERSION 3.0)
project(TU-0002 VERSION 1.0)

include (../../../cmake/usr_paths.cmake)

set(TEST_NAME tu_2)

set(SRC test_2.cpp usr_fct/src/usr_fct.cpp)

include_directories(${USR_FCT_INC_DIR})

add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

#add_custom_target(${PROJECT_NAME}.run
#    COMMAND ${BUILD_UNIT_TESTS_DIR}/TU-0002/tu_2
#    DEPENDS ${PROJECT_NAME}.build
#)

add_executable(${TEST_NAME} ${SRC})

target_link_libraries(${TEST_NAME} PUBLIC
    gtest_main
)

if((RUN_MODE STREQUAL "Coverage"))
    #message(WARNING "Code coverage results with an optimised (non-Debug) build may be misleading")
    setup_target_for_coverage_lcov(
        NAME ${PROJECT_NAME}.run  # Name for custom target.
        EXECUTABLE ${TEST_NAME}   # Name of the test driver executable that runs the tests.
    )
else()
    #message(FATAL_ERROR "Compiler is not GNU gcc! Aborting...")
    add_custom_target(${PROJECT_NAME}.run
        COMMAND ${BUILD_UNIT_TESTS_DIR}/TU-0002/tu_2
        DEPENDS ${PROJECT_NAME}.build
    )
endif()