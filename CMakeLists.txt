cmake_minimum_required(VERSION 3.3)
project(graph_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 13-1/areamap.c)
add_executable(graph_algorithm ${SOURCE_FILES})