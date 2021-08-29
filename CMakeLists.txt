#top level CMakeLists
cmake_minimum_required(VERSION 3.16)
# set project name
project(21f_pa01_arthur_zhang)


set(EXE_NAME art)

set (input01 "input.txt")

set(CMAKE_CXX_STANDARD 14)

add_executable(${EXE_NAME} src/main.cpp src/painting.cpp src/painting.h)