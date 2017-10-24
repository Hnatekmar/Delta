cmake_minimum_required(VERSION 3.8)
project(Engine)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Engine.cpp Engine.h)
add_library(Engine ${SOURCE_FILES})
target_link_libraries(Engine ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES})