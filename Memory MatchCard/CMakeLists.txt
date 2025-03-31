cmake_minimum_required(VERSION 3.29)
project(PROGV2)

set(CMAKE_CXX_STANDARD 14)

include_directories(v2/ML2Progv2)

add_executable(PROGV2
    v2/ML2Progv2/BonusCard.h
    v2/ML2Progv2/Card.h
    v2/ML2Progv2/Deck.cpp
    v2/ML2Progv2/Deck.h
    v2/ML2Progv2/Game.cpp
    v2/ML2Progv2/Game.h
    v2/ML2Progv2/main.cpp
    v2/ML2Progv2/PenaltyCard.h
    v2/ML2Progv2/Player.h
    v2/ML2Progv2/StandardCard.h)
