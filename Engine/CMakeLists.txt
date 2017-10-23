cmake_minimum_required(VERSION 3.8)
project(Engine)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Engine.cpp Engine.h)
add_library(Engine ${SOURCE_FILES})