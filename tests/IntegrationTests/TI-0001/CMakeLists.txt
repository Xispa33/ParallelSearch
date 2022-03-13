cmake_minimum_required(VERSION 3.18)
project(TI-0001 VERSION 1.0)

include (../../../cmake/usr_paths.cmake)

set(TEST_NAME ti_1)
set(SRC ti_1.cpp)

add_executable(${TEST_NAME} ${SRC})

# Include directories needed to compile the source files
include_directories(
  ${ENGINE_INC_DIR}
  ${WORDS_LIST_INC_DIR}
  ${TOOLS_INC_DIR}
  ${USR_FCT_INC_DIR}
)

add_custom_target(${PROJECT_NAME}.build
  COMMAND make
)

# Commands to run when build the <TI-0001> target
add_custom_target(${PROJECT_NAME}.run
  COMMAND ${BUILD_INTEGRATION_TESTS_DIR}/TI-0001/ti_1
  DEPENDS ${PROJECT_NAME}.build
)

target_link_libraries(${TEST_NAME} PUBLIC
  lengine
)

#set (CMAKE_CXX_FLAGS "-DNDEBUG")