cmake_minimum_required(VERSION 2.8.12.2)
project(Project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Person.cpp Person.h OptimizedAirport.cpp OptimizedAirport.h Event.cpp Event.h)
add_executable(Project2 ${SOURCE_FILES})