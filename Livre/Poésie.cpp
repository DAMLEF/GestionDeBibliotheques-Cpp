# include "Poésie.h"

static const string CATÉGORIE = "Poésie";

const string poésieVers = "Vers";
const string poésieProse = "Prose";
extern const string poésieVersEtProse = "Vers et Prose";




Poésie::Poésie(const string &isbn, const int code, const string &auteur, const string &titre, const string &éditeur,
    const string &publicCible, const string &indicateur):
Livre(isbn, code, auteur, titre, éditeur, publicCible, CATÉGORIE) {
    this->indicateur = indicateur;
}


const string &Poésie::getIndicateur() const {
    return this->indicateur;
}

void Poésie::afficherLivre() const {
    Livre::afficherLivre();

    std::cout << "--- > Spécification de la "<< CATÉGORIE << std::endl;
    std::cout << "Indicateur   : " << indicateur << std::endl;

    std::cout << "---------------------------------------------\n";
}


