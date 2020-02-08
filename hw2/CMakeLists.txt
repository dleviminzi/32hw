cmake_minimum_required(VERSION 3.15)
project(hw2_daniel_levi_minzi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw2_daniel_levi_minzi
        eval.cpp
        Map.cpp
        Map.h)
