cmake_minimum_required(VERSION 3.14)
project(DirectedGraph)

set(CMAKE_CXX_STANDARD 14)

add_executable(DirectedGraph main.cpp Digraph.cpp
        DirectedDFS.cpp KosarajuSharirSCC.cpp DepthFirstOrder.cpp)