cmake_minimum_required(VERSION 3.28)
project(AlternativeLanguageProj)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AlternativeLanguageProj
        Cell.cpp
        Cell.h
        CellData.cpp
        Main.h
        Main.cpp)
