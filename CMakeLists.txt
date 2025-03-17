cmake_minimum_required(VERSION 3.30)
project(compilerpart1)

set(CMAKE_CXX_STANDARD 20)

add_executable(compilerpart1 main.cpp
        LexAnalyzer.cpp
        LexAnalyzer.h)
