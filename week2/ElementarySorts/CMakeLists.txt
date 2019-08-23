cmake_minimum_required(VERSION 3.14)
project(ElementarySorts)

set(CMAKE_CXX_STANDARD 14)

add_executable(ElementarySorts main.cpp SelectionSort.h InsertionSort.h ShellSort.h)