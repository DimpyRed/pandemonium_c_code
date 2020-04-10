cmake_minimum_required(VERSION 3.14)
project(Pandemonium_c_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pandemonium_c_code
        library.cpp
        library.h
        Piece.cpp
        Piece.h)
