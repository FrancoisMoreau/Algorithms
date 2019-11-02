cmake_minimum_required(VERSION 3.14)
project(Kd_Trees)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(OpenCV REQUIRED)

include_directories(
        ${CMAKE_INCLUDE_CURRENT_DIR}
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR})

SET(SRC main.cpp Point2D.cpp PointSET.cpp)

add_executable(Kd_Trees ${SRC})

target_link_libraries(Kd_Trees ${OpenCV_LIBS})