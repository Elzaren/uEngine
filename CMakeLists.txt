cmake_minimum_required(VERSION 3.13)
project(uEngine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp window.cpp)

add_executable(uEngine ${SOURCE_FILES})


set(GLFW_PATH "$ENV{GLFW_PATH}")
include_directories("${GLFW_PATH}/include")
target_link_libraries(uEngine "${GLFW_PATH}/lib-mingw-w64/libglfw3.a")
target_link_libraries(uEngine opengl32)