cmake_minimum_required(VERSION 3.29)
project(GestionBibliotheques_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(Livre)
include_directories(Bibliothèque)
include_directories(Adhérent)
include_directories(ListeChainée)
include_directories(Exception)

add_executable(GestionBibliotheques_Cpp
    Livre/Livre.cpp
    Livre/Livre.h
    Bibliothèque/Bibliothèque.cpp
    Bibliothèque/Bibliothèque.h
    Adhérent/Adhérent.cpp
    Adhérent/Adhérent.h
    Exception/LimiteAtteinte.cpp
    Exception/LimiteAtteinte.h
    Exception/SaisieInvalide.cpp
    Exception/SaisieInvalide.h

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
        Bibliothèque/Prêt.cpp
        Bibliothèque/Prêt.h
        ListeChainée/LivreLC.cpp
        ListeChainée/LivreLC.h
        Exception/LimiteAtteinte.cpp
        Exception/LimiteAtteinte.h
        Exception/SaisieInvalide.cpp
        Exception/SaisieInvalide.h

)
