cmake_minimum_required(VERSION 3.0)
project(PARALLEL-SEARCH VERSION 1.0.0)

include(cmake/CodeCoverage.cmake)

# Cette commande doit etre optionnelle
SET(CMAKE_CXX_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")
#SET(CMAKE_C_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")

add_subdirectory(search_engine)
add_subdirectory(tests)