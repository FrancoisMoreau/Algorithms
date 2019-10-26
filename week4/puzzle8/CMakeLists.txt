cmake_minimum_required(VERSION 3.14)
project(puzzle8)

set(CMAKE_CXX_STANDARD 14)

set(SRC main.cpp Board.cpp Solver.cpp)

add_executable(puzzle8 ${SRC})
