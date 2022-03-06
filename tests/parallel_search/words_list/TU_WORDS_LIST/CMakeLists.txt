cmake_minimum_required(VERSION 3.8)

set(TEST_NAME tu_words_list)
set(SRC tu_words_list.cpp)

add_executable(${TEST_NAME} ${SRC})

target_link_libraries(${TEST_NAME} PUBLIC
    libwords_list
    gtest_main
)

add_test(NAME ${TEST_NAME}
         COMMAND ${TEST_NAME}
)