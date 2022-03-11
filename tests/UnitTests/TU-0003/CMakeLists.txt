cmake_minimum_required(VERSION 3.8)
project(TU-0003 VERSION 1.0)

set(TEST_NAME tu_3)

set(SRC test_3.cpp 
    usr_functions/src/usr_fct.cpp 
    #../../../search_engine/engine/src/engine.cpp 
    ../../../search_engine/words_list/src/words_list.cpp
)

include_directories(
    ../../../usr_functions/inc 
    ../../../search_engine/engine/inc 
    #../../../search_engine/words_list/inc
)

add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

add_custom_target(${PROJECT_NAME}.run
    COMMAND /Users/brice/Desktop/Codes/ParallelSearch/build/tests/UnitTests/TU-0003/tu_3
    DEPENDS ${PROJECT_NAME}.build
)

add_executable(${TEST_NAME} ${SRC})

target_link_libraries(${TEST_NAME} PUBLIC
    gtest_main
    libeng
)