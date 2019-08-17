cmake_minimum_required(VERSION 3.14)
project(InterviewQuestions)

set(CMAKE_CXX_STANDARD 14)

add_executable(InterviewQuestions main.cpp
        SocialNetworkConnectivity.cpp
        SocialNetworkConnectivity.h
        UFCanonical.cpp
        UFCanonical.h SuccessorDel.cpp SuccessorDel.h)