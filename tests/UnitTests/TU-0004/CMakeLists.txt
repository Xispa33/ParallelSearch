cmake_minimum_required(VERSION 3.0)
project(TU-0004 VERSION 1.0)

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

target_special_setup(${PROJECT_NAME} ${TEST_NAME})