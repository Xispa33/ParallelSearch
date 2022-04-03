cmake_minimum_required(VERSION 3.0)
project(TI-0003 VERSION 1.0)

include (../../../cmake/usr_paths.cmake)

set(TEST_NAME ti_3)
set(SRC ti_3.cpp)

add_executable(${TEST_NAME} ${SRC})

# Include directories needed to compile the source files
include_directories(
  ${ENGINE_INC_DIR}
  ${WORDS_LIST_INC_DIR}
  ${TOOLS_INC_DIR}
  ${USR_FCT_INC_DIR}
)

add_custom_target(${PROJECT_NAME}.build
  COMMAND make
)

target_link_libraries(${TEST_NAME} PUBLIC
  lengine
)

#set (CMAKE_CXX_FLAGS "-DNDEBUG")
#set(COMPILER_FLAGS "INC_LIST_SORT")
#add_definitions(${COMPILER_FLAGS})
#set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS}")
#SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

if((RUN_MODE STREQUAL "Coverage"))
    #message(WARNING "Code coverage results with an optimised (non-Debug) build may be misleading")
    setup_target_for_coverage_lcov(
        NAME ${PROJECT_NAME}.run  # Name for custom target.
        EXECUTABLE ${TEST_NAME}   # Name of the test driver executable that runs the tests.
    )
else()
    #message(FATAL_ERROR "Compiler is not GNU gcc! Aborting...")
    # Commands to run when build the <TI-0001> target
    add_custom_target(${PROJECT_NAME}.run
      COMMAND ${BUILD_INTEGRATION_TESTS_DIR}/TI-0003/ti_3
      DEPENDS ${PROJECT_NAME}.build
    )
endif()