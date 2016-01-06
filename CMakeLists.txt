cmake_minimum_required(VERSION 3.1)
project(Exercise_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -ldl -std=c++11 ")


set(SOURCE_FILES src/main.cpp src/Cinema.cpp src/Actor.cpp src/AgeCompare.cpp
        src/CntrCompare.cpp src/Director.cpp src/IDCompare.cpp src/Inputs.cpp
        src/Movie.cpp src/Producer.cpp src/Professionals.cpp
        src/Screenwriter.cpp src/TCPServer.cpp)

add_executable(ex6_server ${SOURCE_FILES})