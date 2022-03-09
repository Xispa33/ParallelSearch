cmake_minimum_required(VERSION 3.8)

set(This tu_base_math_02_exe)

set(Sources
    base_math.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    base_math
    gtest_main
)

add_test(NAME ${This}
         COMMAND ${This}
)