cmake_minimum_required(VERSION 3.4)
project(OperatorOverloading)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Rational.cpp Rational.h)
add_executable(OperatorOverloading ${SOURCE_FILES})