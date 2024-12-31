# include "Bibliothèque.h"

Bibliothèque::Bibliothèque(int code, const string &nom, const string &adresse) {
    this->code = code;
    this->nom = nom;
    this->adresse = adresse;

    this->nbLivres = 0;
    this->livres = new Livre[100];
    this->max_size = 100;
}



void Bibliothèque::afficherBibliothèque() const {
    std::cout << "=============================================\n";
    std::cout << "\nInformations sur la bibliothèque :\n";
    std::cout << "ID : " << code << "\n";
    std::cout << "Nom : " << nom << "\n";
    std::cout << "Adresse : " << adresse << "\n";
    std::cout << "Nombre de livres : " << nbLivres << "\n";

    std::cout << "---------------------------------------------\n";
}


void Bibliothèque::afficherLivres() const {
    std::cout << "=============================================\n";
    std::cout << "\nBibliothèque - Liste des livres :\n";
    for(int i=0; i < this->nbLivres; i++) {
        this->livres[i].afficherLivre();
    }

    std::cout << "=============================================\n";
}

void Bibliothèque::afficherLivres(const string &catégorie) const {
    std::cout << "=============================================\n";
    std::cout << "\nBibliothèque - Liste des livres :\n";
    for(int i=0; i < this->nbLivres; i++) {
        if(this->livres[i].getCatégorie() == catégorie) {
            this->livres[i].afficherLivre();
        }
    }
    std::cout << "=============================================\n";
}

int Bibliothèque:: getCode() const {
    return code;
}

const string & Bibliothèque:: getNom() const {
    return nom;
}

const string & Bibliothèque:: getAdresse() const {
    return adresse;
}


void Bibliothèque::agrandirTableau() {
    auto* newTab = new Livre[max_size*2];

    for(int i=0; i < max_size; i++) {
        newTab[i] = livres[i];
    }

    delete[] livres;
    livres = newTab;

    max_size *= 2;
}


void Bibliothèque::ajouterLivre(Livre livre) {
    if(nbLivres == max_size) {
        agrandirTableau();
    }

    livre.setCode(nbLivres); //On attribue le code du nouveau livre
    livres[nbLivres] = livre;
    //todo: propriétaire ?

    nbLivres++;
}


