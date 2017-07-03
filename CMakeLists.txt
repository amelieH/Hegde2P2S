cmake_minimum_required(VERSION 3.6)
project(Hedge)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp player.cpp player.h game.cpp game.h)
add_executable(Hedge ${SOURCE_FILES})