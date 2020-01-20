cmake_minimum_required(VERSION 3.14)
project(WordNet)

set(CMAKE_CXX_STANDARD 14)

set(SRC main.cpp
        WordNet.cpp
        SAP.cpp
        Digraph.cpp
        Outcast.cpp)

add_executable(WordNet ${SRC})