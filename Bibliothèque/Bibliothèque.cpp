# include "Bibliothèque.h"

Bibliothèque::Bibliothèque() {
    this->code = -1;
    this->nom = "";
    this->adresse = "";

    this->livres = nullptr;
    this->nbLivres = 0;
    this->max_size = 0;

}


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
    std::cout << "Informations sur la bibliothèque :\n";
    std::cout << "ID : " << code << "\n";
    std::cout << "Nom : " << nom << "\n";
    std::cout << "Adresse : " << adresse << "\n";
    std::cout << "Nombre de livres : " << nbLivres << "\n";

    std::cout << "---------------------------------------------\n";
}


void Bibliothèque::afficherLivres() const {
    std::cout << "=============================================\n";
    std::cout << "Bibliothèque - Liste des livres :\n";
    for(int i=0; i < this->nbLivres; i++) {
        this->livres[i].afficherLivre();
    }

    std::cout << "=============================================\n";
}

void Bibliothèque::afficherLivres(const string &catégorie) const {
    std::cout << "=============================================\n";
    std::cout << "Bibliothèque - Liste des livres (catégorie : " << catégorie << ") :\n";
    for(int i=0; i < this->nbLivres; i++) {
        if(this->livres[i].getCatégorie() == catégorie) {
            this->livres[i].afficherLivre();
        }
    }
    std::cout << "=============================================\n";
}

// Interne
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


void Bibliothèque::emprunterLivre(const int codeLivre) const {
    for(int i=0; i < nbLivres; i++) {
        if(livres[i].getCode() == codeLivre) {
            if(livres[i].getÉtat() == "libre") {
                livres[i].setÉtat("emprunté");
                return;
            }
        }
    }

}


void Bibliothèque::rendreLivre(const int codeLivre) const {
    for(int i=0; i < nbLivres; i++) {
        if(livres[i].getCode() == codeLivre) {
            if(livres[i].getÉtat() == "emprunté") {
                livres[i].setÉtat("libre");
                return;
            }
            cout << "[GB] Erreur : Vous ne pouvez pas rendre un livre qui n'est pas emprunté !";
        }
    }
}

// Option de la bibliothèque
void Bibliothèque::acheterLivre(Livre livre) {
    //todo: vérifions que le livre est neuf (exception try catch)

    std:: cout << "[GB] La Bibliothèque " << nom << " achète le livre : " << livre.getTitre() << std::endl;
    ajouterLivre(livre);
}



// Getters
int Bibliothèque:: getCode() const {
    return code;
}

const string & Bibliothèque:: getNom() const {
    return nom;
}

const string & Bibliothèque:: getAdresse() const {
    return adresse;
}

int Bibliothèque::getNbLivres() const {
    return nbLivres;
}

Livre Bibliothèque::getLivre(const int codeLivre) const {

    for(int i=0; i < nbLivres; i++) {
        if(livres[i].getCode() == codeLivre) {
            return livres[i];
        }
    }

    cout << "[GB] La bibliothèque " << nom << " ne possède pas de livre avec le code " << codeLivre << endl;
    return {};
}


Livre Bibliothèque::getLivre(const string& isbn) const {

    for(int i=0; i < nbLivres; i++) {
        if(livres[i].getIsbn() == isbn) {
            return livres[i];
        }
    }

    cout << "[GB] La bibliothèque " << nom << " ne possède pas de livre avec l'isbn " << isbn << endl;
    return {};
}



