# include "Roman.h"

static const string CATÉGORIE = "Roman";


Roman::Roman(const string &isbn, const int code, const string &auteur, const string &titre, const string &éditeur,
    const string &publicCible, const string &genre):
Livre(isbn, code, auteur, titre, éditeur, publicCible, CATÉGORIE) {
    this->genre = genre;
}

const string& Roman::getGenre() const {
    return this->genre;
}

void Roman::afficherLivre() const {
    Livre::afficherLivre();

    std::cout << "--- > Spécification du "<< CATÉGORIE << std::endl;
    std::cout << "Genre   : " << genre << std::endl;

    std::cout << "---------------------------------------------\n";
}
