project(rational CXX)
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(rcalc
	main.cpp
	rational.cpp)
