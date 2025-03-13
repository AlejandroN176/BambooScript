cmake_minimum_required(VERSION 3.30)
project(Compiler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Compiler main.cpp
        LexAnalyzer.cpp
        LexAnalyzer.h)
