cmake_minimum_required(VERSION 3.15)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw1 main.cpp Vampire.h Player.h Arena.h globals.h Game.h Vampire.cpp Player.cpp Arena.cpp Game.cpp utilities.cpp History.cpp History.h)