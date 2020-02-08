cmake_minimum_required(VERSION 3.15)
project(newMap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(newMap
        CarMap.cpp
        CarMap.h
        main.cpp
        newMap.cpp
        newMap.h)
