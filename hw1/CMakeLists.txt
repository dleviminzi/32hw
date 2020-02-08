cmake_minimum_required(VERSION 3.15)
project(hw_1_daniel_levi_minzi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw_1_daniel_levi_minzi
        main.cpp
        Map.cpp
        Map.h CarMap.cpp CarMap.h)
