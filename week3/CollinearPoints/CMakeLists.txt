cmake_minimum_required(VERSION 3.14)
project(CollinearPoints)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(OpenCV REQUIRED)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR} ${OpenCV_INCLUDE_DIRS})

add_executable(CollinearPoints main.cpp ColPoint.cpp LineSegment.cpp BruteCollinearPoints.cpp BruteCollinearPoints.h)

target_link_libraries(CollinearPoints ${OpenCV_LIBS})