cmake_minimum_required(VERSION 3.14)
project(InQuesMergesort)

set(CMAKE_CXX_STANDARD 14)

add_executable(InQuesMergesort main.cpp SmallArrayMergeSort.cpp SmallArrayMergeSort.h CountInversion.cpp CountInversion.h)