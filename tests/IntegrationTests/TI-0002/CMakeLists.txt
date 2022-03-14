cmake_minimum_required(VERSION 3.0)
project(TI-0002 VERSION 1.0)

include (../../../cmake/usr_paths.cmake)

set(CLIENT_APP client_app)
set(SERVER_APP server_app)

set(SRC_CLIENT client.cpp)
set(SRC_SERVER server.cpp)

include_directories(
  ${ENGINE_INC_DIR}
  ${WORDS_LIST_INC_DIR}
  ${TOOLS_INC_DIR}
  ${USR_FCT_INC_DIR}
)

add_executable(${CLIENT_APP} ${SRC_CLIENT})
add_executable(${SERVER_APP} ${SRC_SERVER})

add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

target_link_libraries(${CLIENT_APP} PUBLIC
    lengine
)

target_link_libraries(${SERVER_APP} PUBLIC
    lengine
)