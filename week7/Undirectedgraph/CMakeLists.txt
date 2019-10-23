cmake_minimum_required(VERSION 3.14)
project(Undirectedgraph)

set(CMAKE_CXX_STANDARD 14)

set(SRC main.cpp
        Udgraph.cpp
        DepthFirstPath.cpp
        BreathFirstPath.cpp
        ConnectedComponents.cpp)

add_executable(Undirectedgraph ${SRC})