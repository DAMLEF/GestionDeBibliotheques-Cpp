# include <iostream>

#include "Livre.h"

Livre::Livre() {
    this->isbn = "";
    this->code = 0;

    this->auteur = "";
    this->titre = "";
    this->éditeur = "";
    this->publicCible = "";

    this->catégorie = "";

    this->état = "libre";   // Par défaut le livre est libre.
}

Livre::Livre(const string& isbn, const int code, const string &auteur, const string &titre, const string& éditeur,
    const string& publicCible, const string& catégorie) {
    this->isbn = isbn;
    this->code = code;

    this->auteur = auteur;
    this->titre = titre;
    this->éditeur = éditeur;
    this->publicCible = publicCible;

    this->catégorie = catégorie;

    this->état = "libre";   // Par défaut le livre est libre.
}


void Livre:: afficherLivre() const {
    std::cout << "---------------------------------------------\n";
    std::cout << "Livre: "<< titre << std::endl << std::endl;

    std::cout << "ISBN        : " << isbn << std::endl;
    std::cout << "Code        : " << code << std::endl;

    std::cout << "Auteur      : " << auteur << std::endl;
    std::cout << "Titre       : " << titre << std::endl;
    std::cout << "Éditeur     : " << éditeur << std::endl;
    std::cout << "Public      : " << publicCible << std::endl;
    std::cout << "Catégorie   : " << catégorie << std::endl;
    std::cout << "État        : " << état << std::endl;

}



// Getters

const string & Livre:: getIsbn() const {
    return isbn;
}

int Livre:: getCode() const {
    return code;
}

const string & Livre:: getAuteur() const {
    return auteur;
}

const string & Livre::getTitre() const {
    return titre;
}

const string & Livre::getÉditeur() const {
    return éditeur;
}

const string & Livre:: getPublicCible() const {
    return publicCible;
}

const string & Livre::getCatégorie() const {
    return catégorie;
}

const string & Livre:: getÉtat() const {
    return état;
};


// Setters

void Livre::setCode(const int code) {
    this->code = code;
}

void Livre::setÉtat(const string &état) {
    this->état = état;
}

