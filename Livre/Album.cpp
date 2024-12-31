# include "Album.h"

static const string CATÉGORIE = "Album";


Album::Album(const string &isbn, const int code, const string &auteur, const string &titre, const string &éditeur,
    const string &publicCible, const bool photos, const bool dessins):
Livre(isbn, code, auteur, titre, éditeur, publicCible, CATÉGORIE) {
    this->photos = photos;
    this->dessins = dessins;
}

bool Album::getPhotos() const {
    return this->photos;
}


bool Album::getDessins() const {
    return this->dessins;
}


void Album::afficherLivre() const {
    Livre::afficherLivre();

    std::cout << "--- > Spécification de l' "<< CATÉGORIE << std::endl;

    if(this->photos) {
        std::cout << "\t - L'album contient des photos " << std::endl;
    }

    if(this->dessins) {
        std::cout << "\t - L'album contient des dessins " << std::endl;
    }

    std::cout << "---------------------------------------------\n";
}

