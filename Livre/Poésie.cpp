# include "Poésie.h"

static const string CATÉGORIE = "Poésie";


Poésie::Poésie(const string &isbn, const int code, const string &auteur, const string &titre, const string &éditeur,
    const string &publicCible, const bool vers, const bool prose):
Livre(isbn, code, auteur, titre, éditeur, publicCible, CATÉGORIE) {
    this->vers = vers;
    this->prose = prose;

    if(!prose && !vers) {
        //todo: Exception
        std:: cout << "[GB] Erreur de saisie : La poésie est nécessairement soit en prose soit en vers" << endl;
    }
}


bool Poésie::getVers() const {
    return this->vers;
}

bool Poésie::getProse() const {
    return this->prose;
}

void Poésie::afficherLivre() const {
    Livre::afficherLivre();

    std::cout << "--- > Spécification de la "<< CATÉGORIE << std::endl;
    if(vers && prose) {
        std::cout << "Poésie en vers et en prose" << std::endl;
    }
    else if(vers && !prose) {
        std::cout << "Poésie en vers" << std::endl;
    }
    else if(!vers && prose) {
        std::cout << "Poésie en prose" << std::endl;
    }



    std::cout << "---------------------------------------------\n";
}


