cmake_minimum_required(VERSION 3.14)
project(QuickSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(QuickSort main.cpp QuickSort.cpp QuickSort.h FastQuickSort.cpp FastQuickSort.h QuickSelect.cpp QuickSelect.h ThreeWayPartition.cpp ThreeWayPartition.h)