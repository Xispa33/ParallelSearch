cmake_minimum_required(VERSION 3.0)
project(PARALLEL-SEARCH VERSION 1.0.0)

include(cmake/CodeCoverage.cmake)
include(cmake/usr_paths.cmake)

if ((RUN_MODE STREQUAL "Coverage"))
    set(CMAKE_CXX_FLAGS "-g -O0 --coverage -fno-exceptions -fprofile-arcs -ftest-coverage")
endif()

add_subdirectory(search_engine)
add_subdirectory(tests)