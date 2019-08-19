cmake_minimum_required(VERSION 3.14)
project(StacksQueue)

set(CMAKE_CXX_STANDARD 14)

add_executable(StacksQueue main.cpp SmallVec.h Blob.h Linked_list_stack.h Resizing_array_stack.h Linked_list_queue.h)