cmake_minimum_required(VERSION 3.18)

set(APP_NAME client)

add_custom_target(${APP_NAME}.build)
add_dependencies(${APP_NAME}.build
    ${APP_NAME}
)

#add_dependencies(${APP_NAME}.run
#    ${APP_NAME}.build
#)

add_custom_target(${APP_NAME}.run
  COMMAND echo "TOTOO\n"
  DEPENDS ${APP_NAME}.build
)

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME} PUBLIC 
    libusr_fct
)
