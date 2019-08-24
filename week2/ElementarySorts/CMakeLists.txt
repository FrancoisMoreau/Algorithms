cmake_minimum_required(VERSION 3.14)
project(ElementarySorts)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

add_executable(ElementarySorts main.cpp ConvexHull.cpp ConvexHull.h)

target_link_libraries(ElementarySorts ${OpenCV_LIBS})