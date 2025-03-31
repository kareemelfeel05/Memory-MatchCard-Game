cmake_minimum_required(VERSION 3.28.1)
project(ML2Prog)

set(CMAKE_CXX_STANDARD 20)

add_executable(ML2Prog main.cpp
        Game.cpp
        Deck.cpp)
