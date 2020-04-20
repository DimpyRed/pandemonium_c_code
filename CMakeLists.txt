cmake_minimum_required(VERSION 3.14)
project(Pandemonium_c_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pandemonium_c_code
        Piece.cpp
        Piece.h GameState.cpp GameState.h Position.h move.h)
