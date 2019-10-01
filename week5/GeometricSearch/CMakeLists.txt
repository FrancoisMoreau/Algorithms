cmake_minimum_required(VERSION 3.14)
project(GeometricSearch)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(OpenCV REQUIRED)

include_directories(
        ${CMAKE_INCLUDE_CURRENT_DIR}
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR})

SET(SRC_FILES
        main.cpp
        SweepLine.cpp
        RangeSearch.cpp)

add_executable(GeometricSearch ${SRC_FILES})

target_link_libraries(GeometricSearch ${OpenCV_LIBS})