cmake_minimum_required(VERSION 3.18)
project(PARALLEL_SEARCH VERSION 1.0.0)

enable_testing()

# parallel_search folder contains different librairies needed for 
# the creation of the executable. Each library corresponds to a class.
# All libraries need to be compiled before main librairy.
#add_subdirectory(parallel_search/search_engine)
#add_subdirectory(parallel_search/threads)
#add_subdirectory(parallel_search/client)
#add_subdirectory(parallel_search/server)
add_subdirectory(parallel_search/words_list)
add_subdirectory(parallel_search/main)

add_subdirectory(tests/parallel_search)
add_subdirectory(tests/googletest)