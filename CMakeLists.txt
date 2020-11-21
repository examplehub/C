cmake_minimum_required(VERSION 3.12.4)

project(Examples C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(ciphers)
add_subdirectory(conversions)
add_subdirectory(dynamicprogramming)
add_subdirectory(maths)
add_subdirectory(sorts)
add_subdirectory(strings)
add_subdirectory(searches)
add_subdirectory(projecteuler)

add_executable(C main.c)