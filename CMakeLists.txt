cmake_minimum_required(VERSION 3.17)
project(motorola)

set(CMAKE_CXX_STANDARD 14)

add_executable(motorola main.cpp functions.cpp functions.h fence.cpp fence.h)