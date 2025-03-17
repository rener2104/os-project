cmake_minimum_required(VERSION 3.30)
project(OS)

set(CMAKE_CXX_STANDARD 20)

add_executable(OS main.cpp auth.cpp
        Process.cpp
        Process.h
        scheduler.cpp
        scheduler.h)
