cmake_minimum_required(VERSION 3.14)
project(MST)

set(CMAKE_CXX_STANDARD 14)

add_executable(MST
        Edge.cpp
        Edgeweightedgraph.cpp
        KruskalMST.cpp
        UF.cpp
        LazyPrimMST.cpp
        main.cpp)