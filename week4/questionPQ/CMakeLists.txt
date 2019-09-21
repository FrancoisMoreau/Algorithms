cmake_minimum_required(VERSION 3.14)
project(questionPQ)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS "-O1 -g -fsanitize=address -fno-omit-frame-pointer -Wall")

add_executable(questionPQ main.cpp DynamicMedian.h DynamicMedian.cpp TaxicabNumber.cpp)