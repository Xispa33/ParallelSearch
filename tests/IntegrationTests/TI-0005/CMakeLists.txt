cmake_minimum_required(VERSION 3.0)
project(TI-0005 VERSION 1.0)

set(TEST_NAME ti_5)
set(SRC ti_5.cpp)

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

target_link_libraries(${TEST_NAME} PUBLIC
  gtest_main
  gmock_main
)

#set (CMAKE_CXX_FLAGS "-DNDEBUG")
#set(COMPILER_FLAGS "INC_LIST_SORT")
#add_definitions(${COMPILER_FLAGS})
#set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS}")
#SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

target_special_setup(${PROJECT_NAME} ${TEST_NAME})