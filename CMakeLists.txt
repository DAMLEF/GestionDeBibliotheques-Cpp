cmake_minimum_required(VERSION 3.29)
project(GestionBibliotheques_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(Livre)

add_executable(GestionBibliotheques_Cpp
    Livre/Livre.cpp
    Livre/Livre.h
    Bibliothèque/Bibliothèque.cpp
    Bibliothèque/Bibliothèque.h

    main.cpp
        Livre/BD.cpp
        Livre/BD.h
        Livre/Poésie.cpp
        Livre/Poésie.h
        Livre/Roman.cpp
        Livre/Roman.h
        Livre/Album.cpp
        Livre/Album.h
        Livre/Théâtre.cpp
        Livre/Théâtre.h
)
