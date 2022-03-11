cmake_minimum_required(VERSION 3.8)

set(This tu_main_02_exe)

set(Sources
    main.cpp
)

add_executable(${This} ${Sources})

#include_directories("/Users/brice/Desktop/Codes/GoogleTest/C_base")

target_link_libraries(${This} PUBLIC
    base_math
    advanced_math
    gtest_main
)

add_test(NAME ${This}
         COMMAND ${This}
)