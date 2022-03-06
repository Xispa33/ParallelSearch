cmake_minimum_required(VERSION 3.18)

set(APP_NAME search_app)

add_custom_target(${APP_NAME}.build)
add_dependencies(${APP_NAME}.build
    ${APP_NAME}
)

add_custom_target(${APP_NAME}.run)
add_dependencies(${APP_NAME}.run
    ${APP_NAME}.build
)

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME} PUBLIC 
    libwords_list
)

#set_target_properties(app_exe PROPERTIES 
#    SUFFIX .exe
#)