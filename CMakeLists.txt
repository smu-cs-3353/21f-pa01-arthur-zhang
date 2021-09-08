#top level CMakeLists
cmake_minimum_required(VERSION 3.16)
# set project name
project(21f_pa01_arthur_zhang)


set(EXE_NAME art)

set (input01 "test/input.txt")

set(CMAKE_CXX_STANDARD 14)

# Copy data files to build dir
foreach(file IN LISTS input01 )
    configure_file(${file} ${file} COPYONLY)
endforeach()

add_executable(${EXE_NAME} src/main.cpp src/painting.cpp src/painting.h src/manager.cpp src/manager.h src/wall.cpp src/wall.h)