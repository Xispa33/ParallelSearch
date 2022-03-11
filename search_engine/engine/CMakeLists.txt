cmake_minimum_required(VERSION 3.18)
project(engine VERSION 1.0)

# First argument is the name of the library, next the files needed
# to compile this librairy. By default, a STATIC librairy is compiled.
# To change STATIC to SHARED by default, run from the build directory:
# cmake -D BUILD_SHARED_LIBS=TRUE ..
add_library(libeng
    src/engine.cpp
    ../words_list/src/words_list.cpp
    ../tools/src/tools.cpp
    ../../usr_functions/src/usr_fct.cpp
    #../words_list/inc/words_list.h
    #../../usr_functions/inc/usr_fct.h
)

target_include_directories(libeng PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc 
    ../../usr_functions/inc 
    ../tools/inc
    ../words_list/inc)

# If PUBLIC is changed to PRIVATE, the constant CXX_VERSION will no 
# longer be seen from the main.cpp. Only the librairy base_cxx will be 
# able to use CXX_VERSION constant.
# If PUBLIC is changed to INTERFACE, it is the opposite. base_cxx won't
# be able to call the constant. INTERFACE has the opposite effect of PRIVATE.
target_compile_definitions(libeng PUBLIC CXX_VERSION=11)

#target_link_libraries(libeng PUBLIC 
#    libwords_list
#)

add_custom_target(${PROJECT_NAME}
    COMMAND make
)

set_target_properties(${TEST_NAME} PROPERTIES 
    SUFFIX .a
)