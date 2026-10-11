cmake_minimum_required(VERSION 3.10)
project(apple_eating)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra")

add_executable(code debug.cpp)