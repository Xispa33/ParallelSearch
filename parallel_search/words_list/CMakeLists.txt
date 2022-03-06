# First argument is the name of the library, next the files needed
# to compile this librairy. By default, a STATIC librairy is compiled.
# To change STATIC to SHARED by default, run from the build directory:
# cmake -D BUILD_SHARED_LIBS=TRUE ..
add_library(
    libwords_list
    inc/words_list.h
    src/words_list.cpp
)

target_include_directories(libwords_list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# If PUBLIC is changed to PRIVATE, the constant CXX_VERSION will no 
# longer be seen from the main.cpp. Only the librairy base_cxx will be 
# able to use CXX_VERSION constant.
# If PUBLIC is changed to INTERFACE, it is the opposite. base_cxx won't
# be able to call the constant. INTERFACE has the opposite effect of PRIVATE.
target_compile_definitions(libwords_list PUBLIC CXX_VERSION=11)