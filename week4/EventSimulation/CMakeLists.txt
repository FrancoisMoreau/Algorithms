cmake_minimum_required(VERSION 3.14)
project(EventSimulation)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC main.cpp Particle.cpp CollisionSystem.cpp)

add_executable(EventSimulation ${SRC})

target_link_libraries(EventSimulation ${OpenCV_LIBS})