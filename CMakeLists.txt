cmake_minimum_required(VERSION 3.29)
project(GestionBibliotheques_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(Livre)

add_executable(GestionBibliotheques_Cpp
    Livre/Livre.cpp
    Livre/Livre.h
    main.cpp)
