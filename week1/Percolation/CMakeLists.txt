cmake_minimum_required(VERSION 3.14)
project(Percolation)

set(CMAKE_CXX_STANDARD 14)

add_executable(Percolation main.cpp Percolation.cpp Percolation.h PercolationStates.cpp PercolationStates.h)