cmake_minimum_required(VERSION 3.8)
project(TU-0004 VERSION 1.0)

include (../../../cmake/usr_paths.cmake)

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

add_custom_target(${PROJECT_NAME}.run
    COMMAND ${BUILD_UNIT_TESTS_DIR}/TU-0004/tu_4
    DEPENDS ${PROJECT_NAME}.build
)

add_executable(${TEST_NAME} ${SRC})

target_link_libraries(${TEST_NAME} PUBLIC
    gtest_main
)