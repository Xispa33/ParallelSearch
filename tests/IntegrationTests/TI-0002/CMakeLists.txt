cmake_minimum_required(VERSION 3.18)
project(TI-0002 VERSION 1.0)

set(CLIENT_APP client_app)
set(SERVER_APP server_app)

set(SRC_CLIENT client.cpp)
set(SRC_SERVER server.cpp)

include_directories(../../../search_engine/engine/inc)

add_executable(${CLIENT_APP} ${SRC_CLIENT})
add_executable(${SERVER_APP} ${SRC_SERVER})

add_custom_target(${PROJECT_NAME})
add_custom_target(${PROJECT_NAME}.build
    COMMAND make
)

#add_custom_target(${PROJECT_NAME}.run
#  COMMAND /Users/brice/Desktop/Codes/ParallelSearch/build/tests/IntegrationTests/TI-0001/ti_1
#  DEPENDS ${PROJECT_NAME}.build
#)

target_link_libraries(${CLIENT_APP} PUBLIC
    libeng
)

target_link_libraries(${SERVER_APP} PUBLIC
    libeng
)