cmake_minimum_required(VERSION 3.1)

project(RealEngine)

set (CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)
set(GL_LIBRARY GL GLU X11)

find_package(GLEW REQUIRED)


include_directories(".")

file(GLOB_RECURSE RealEngine_SRC
    "*.h"
    "*.cpp"
    "*.hpp"
)

add_executable(${PROJECT_NAME} ${RealEngine_SRC})

target_link_libraries(${PROJECT_NAME} glfw ${GL_LIBRARY} m)
target_link_libraries(${PROJECT_NAME} GLEW)
target_link_libraries(${PROJECT_NAME} -lpthread)

