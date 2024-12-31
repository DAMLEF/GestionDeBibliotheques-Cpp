# include "Théâtre.h"

static const string CATÉGORIE = "Théâtre";


Théâtre::Théâtre(const string &isbn, const int code, const string &auteur, const string &titre, const string &éditeur,
    const string &publicCible, const int siècle):
Livre(isbn, code, auteur, titre, éditeur, publicCible, CATÉGORIE) {
    this->siècle = siècle;
}

int Théâtre::getSiècle() const {
    return this->siècle;
}


void Théâtre::afficherLivre() const {
    Livre::afficherLivre();

    std::cout << "--- > Spécification du "<< CATÉGORIE << std::endl;
    if(siècle==1) {
        std::cout << "Siècle   : " << siècle << "er" << std::endl;
    }
    else {
        std::cout << "Siècle   : " << siècle << "e" << std::endl;
    }

    std::cout << "---------------------------------------------\n";

}
