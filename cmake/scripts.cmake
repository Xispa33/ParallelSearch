#include(usr_paths.cmake)

function(find_test_id TEST_ID)
    #message("CURRENT_DIR = " ${CMAKE_CURRENT_SOURCE_DIR})
    #message("CURRENT_FILE = " ${CMAKE_CURRENT_LIST_FILE})
    get_filename_component(FNAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set(${TEST_ID} ${FNAME} PARENT_SCOPE)
endfunction()

function(target_special_setup PROJECT_NAME TEST_NAME)
    set(TEST_ID "")
    find_test_id(TEST_ID)

    set(GTEST_OPTIONS "--gtest_output=xml:${TEST_ID}_report.xml")

    if(TEST_ID MATCHES "^TU")
        set(BUILD_DIR ${BUILD_UNIT_TESTS_DIR})
    elseif(TEST_ID MATCHES "^TI")
        set(BUILD_DIR ${BUILD_INTEGRATION_TESTS_DIR})
    endif()

    if((RUN_MODE STREQUAL "Coverage"))
        setup_target_for_coverage_lcov(
            NAME ${PROJECT_NAME}.run  # Name for custom target.
            EXECUTABLE ${TEST_NAME}   # Name of the test driver executable that runs the tests.
        )
    else()
        add_custom_target(${PROJECT_NAME}.run
            COMMAND ${BUILD_DIR}/${TEST_ID}/${TEST_NAME} ${GTEST_OPTIONS}
            DEPENDS ${PROJECT_NAME}.build
        )
    endif()
endfunction()
#