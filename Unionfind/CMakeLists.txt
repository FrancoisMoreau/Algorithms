cmake_minimum_required(VERSION 3.14)
project(Unionfind)

set(CMAKE_CXX_STANDARD 14)

add_executable(Unionfind main.cpp QuickFind.cpp QuickFind.h QuickUnion.cpp QuickUnion.h WeightedQuickUnion.cpp WeightedQuickUnion.h)