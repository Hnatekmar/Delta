cmake_minimum_required(VERSION 3.2.2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(EpsilonEngine)

add_executable(spacer main.cpp)

target_link_libraries(spacer EpsilonEngine)