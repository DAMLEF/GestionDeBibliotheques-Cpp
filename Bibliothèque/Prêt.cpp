# include "Prêt.h"

#include <iostream>

Prêt::Prêt() {
    this->propriétaireBCode = -1;
    this->codePropriétaire = -1;
    this->codePrêt = -1;
}

Prêt::Prêt(int propriétaireLivreCode, int codePropriétaire, int codePrêt) {
    this->propriétaireBCode = propriétaireLivreCode;
    this->codePropriétaire = codePropriétaire;
    this->codePrêt = codePrêt;
}

void Prêt::afficher() const {
    std:: cout << "---------------------------------------------" <<std::  endl;
    std:: cout << "Bibliothèque propriétaire :" << propriétaireBCode << std:: endl;
    std:: cout << "Code du Prêt              :" << codePrêt << std:: endl;
    std:: cout << "Code d'origine du livre   :" << codePropriétaire << std:: endl;
    std:: cout << "---------------------------------------------" <<std::  endl;

}


int Prêt::getCodePrêt() const {
    return codePrêt;
}

int Prêt::getPropriétaire() const {
    return propriétaireBCode;
}
