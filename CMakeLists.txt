cmake_minimum_required(VERSION 3.16)
project(NameApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core)

# Copia il file styles.qss nella directory di build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/src/styles.qss
    DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
