cmake_minimum_required(VERSION 3.0)
project(engine VERSION 1.0)

include (../../cmake/usr_paths.cmake)

set(LIBNAME lengine)

# First argument is the name of the library, next the files to compile to generate the library.
add_library(${LIBNAME}
    src/engine.cpp
    ${WORDS_LIST_SRC_DIR}/words_list.cpp
    ${TOOLS_SRC_DIR}/tools.cpp
    ${USR_FCT_SRC_DIR}/usr_fct.cpp
    
)

# Include directories needed to compile the source files
include_directories(${USR_FCT_INC_DIR}
    ${ENGINE_INC_DIR} 
    ${TOOLS_INC_DIR}
    ${WORDS_LIST_INC_DIR}
)
#target_include_directories(
#    ${USR_FCT_INC_DIR}
#)

#target_compile_definitions(${LIBNAME} PUBLIC CXX_VERSION=11 INC_LIST_SORT)
target_compile_definitions(${LIBNAME} PUBLIC CXX_VERSION=11)

# Commands to run when build the <engine> target
add_custom_target(${PROJECT_NAME}
    COMMAND make
)

# Adding a ".a" extension to libengine
set_target_properties(${LIBNAME} PROPERTIES 
    SUFFIX .a
)