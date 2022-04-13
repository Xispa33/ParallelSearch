cmake_minimum_required(VERSION 3.0)
project(PARALLEL-SEARCH VERSION 1.0.0)

include(cmake/usr_paths.cmake)
include(cmake/scripts.cmake)
include(cmake/compile.cmake)
include(cmake/CodeCoverage.cmake)


add_subdirectory(search_engine)
add_subdirectory(tests)