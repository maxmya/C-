cmake_minimum_required(VERSION 3.5)
project(CaesarCipher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CaesarCipher.cpp CaesarCipher.h)
add_executable(CaesarCipher ${SOURCE_FILES})