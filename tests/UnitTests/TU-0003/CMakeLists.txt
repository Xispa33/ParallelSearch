cmake_minimum_required(VERSION 3.0)
project(TU-0003 VERSION 1.0)

include (../../../cmake/usr_paths.cmake)
include (../../../cmake/codeCoverage.cmake)

set(TEST_NAME tu_3)

set(SRC test_3.cpp 
    usr_fct/src/usr_fct.cpp 
    ${WORDS_LIST_SRC_DIR}/words_list.cpp
    ${TOOLS_SRC_DIR}/tools.cpp
)

include_directories(
    ${USR_FCT_INC_DIR}
    ${WORDS_LIST_INC_DIR}
    ${TOOLS_INC_DIR}
)

add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

#add_custom_target(${PROJECT_NAME}.run
#    COMMAND ${BUILD_UNIT_TESTS_DIR}/TU-0003/tu_3
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
        COMMAND ${BUILD_UNIT_TESTS_DIR}/TU-0003/tu_3
        DEPENDS ${PROJECT_NAME}.build
    )
endif()

#SETUP_TARGET_FOR_COVERAGE(
#    coverage_${TEST_NAME}  # Name for custom target.
#    ${TEST_NAME}         # Name of the test driver executable that runs the tests.
    # NOTE! This should always have a ZERO as exit code
    # otherwise the coverage generation will not complete.
#    ${BUILD_UNIT_TESTS_DIR}/TU-0003/Coverage     # Name of output directory.
#)