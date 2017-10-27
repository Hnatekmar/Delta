cmake_minimum_required(VERSION 3.8)
project(Engine)

find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Shaders/default.frag
        DESTINATION ${CMAKE_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Shaders/default.vert
        DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCE_FILES Engine.cpp Engine.h IDrawable.h Primitives/Cube.cpp Primitives/Cube.h Shader.cpp Shader.h VBO.h)
add_library(Engine ${SOURCE_FILES})
target_link_libraries(Engine ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${GLM_LIBRARIES})
