cmake_minimum_required(VERSION 3.15)
project(pr2_daniel_levi_minzi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pr2_daniel_levi_minzi
        Map.cpp
        Map.h
        map_ll.cpp)
