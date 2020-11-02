cmake_minimum_required(VERSION 3.12.4)

project(Examples C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(maths)
add_subdirectory(sorts)

add_executable(C main.c)