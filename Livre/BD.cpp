# include "BD.h"



static const string CATÉGORIE = "Bande dessiné";

BD::BD(const string &isbn, const int code, const string &auteur, const string &titre, const string &éditeur,
    const string &publicCible, const string &dessinateur):
Livre(isbn, code, auteur, titre, éditeur, publicCible, CATÉGORIE) {
    this->dessinateur = dessinateur;
}

const string &BD::getDessinateur() const{
    return this->dessinateur;
}

void BD::afficherLivre() const {
    Livre::afficherLivre();

    std::cout << "--- > Spécification de la "<< CATÉGORIE << std::endl;
    std::cout << "Dessinateur   : " << dessinateur << std::endl;

    std::cout << "---------------------------------------------\n";

}




