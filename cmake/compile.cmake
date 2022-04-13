# Compilations flags

if ((RUN_MODE STREQUAL "Coverage"))
    set(CMAKE_CXX_FLAGS "-g -O0 --coverage -fno-exceptions -fprofile-arcs -ftest-coverage")
endif()