cmake_minimum_required(VERSION 3.0)
project(TU-0004 VERSION 1.0)

include (../../../cmake/usr_paths.cmake)
include (../../../cmake/codeCoverage.cmake)

set(TEST_NAME tu_4)

set(SRC test_4.cpp 
    usr_fct/src/usr_fct.cpp 
    ${ENGINE_SRC_DIR}/engine.cpp 
    ${WORDS_LIST_SRC_DIR}/words_list.cpp
    ${TOOLS_SRC_DIR}/tools.cpp
)

include_directories(
    ${USR_FCT_INC_DIR}
    ${ENGINE_INC_DIR}
    ${WORDS_LIST_INC_DIR}
    ${TOOLS_INC_DIR}
)

add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

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
        COMMAND ${BUILD_UNIT_TESTS_DIR}/TU-0004/tu_4
        DEPENDS ${PROJECT_NAME}.build
    )
endif()

#setup_target_for_coverage_lcov(
#    NAME coverage_${TEST_NAME}  # Name for custom target.
#    EXECUTABLE ${TEST_NAME}         # Name of the test driver executable that runs the tests.
    # NOTE! This should always have a ZERO as exit code
    # otherwise the coverage generation will not complete.
#    ${BUILD_UNIT_TESTS_DIR}/TU-0004/Coverage     # Name of output directory.
#)

#append_coverage_compiler_flags()

#setup_target_for_coverage_gcovr_xml(
#     NAME coverage_${TEST_NAME}   # New target name
#     EXECUTABLE ${TEST_NAME} # Executable in PROJECT_BINARY_DIR
     #DEPENDENCIES ${TEST_NAME}         # Dependencies to build first
     #BASE_DIRECTORY ${SEARCH_ENGINE_DIR} # Base directory for report
#                                            #  (defaults to PROJECT_SOURCE_DIR)
#     EXCLUDE "src/dir1/*" "src/dir2/*"      # Patterns to exclude (can be relative
#                                            #  to BASE_DIRECTORY, with CMake 3.4+)
#)