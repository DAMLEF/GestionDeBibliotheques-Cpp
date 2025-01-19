# include "Bibliothèque.h"


Bibliothèque::Bibliothèque() {
    this->code = -1;
    this->nom = "";
    this->adresse = "";

    this->livres = LivreLC();
    this->nbLivres = 0;
    this->maxCode = 0;

    this->prêts = new Prêt[100];
    this->nbPrêts = 0;
    this->tailleTableauPrêts = 100;

}


Bibliothèque::Bibliothèque(int code, const string &nom, const string &adresse) {
    this->code = code;
    this->nom = nom;
    this->adresse = adresse;

    this->nbLivres = 0;
    this->livres = LivreLC();
    this->maxCode = 0;

    this->prêts = new Prêt[100];
    this->nbPrêts = 0;
    this->tailleTableauPrêts = 100;

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

void Bibliothèque::afficherLivres(){
    std::cout << "=============================================\n";
    std::cout << "Bibliothèque - Liste des livres :\n";
    livres.afficherListe();
    std::cout << "=============================================\n";
}

void Bibliothèque::afficherLivres(const string &catégorie){
    std::cout << "=============================================\n";
    std::cout << "Bibliothèque - Liste des livres (catégorie : " << catégorie << ") :\n";
    livres.afficherListe(catégorie);
    std::cout << "=============================================\n";
}

// Interne
void Bibliothèque::ajouterLivre(Livre* livre) {

    livre->setCode(maxCode); //On attribue le code du nouveau livre
    livres.ajouterLivre(livre);

    nbLivres++;
    maxCode++;
}

void Bibliothèque::retirerLivre(int codeLivre) {
    Livre* l = getLivre(codeLivre);

    if(l->getCode() != -1) {
        livres.retirerLivre(codeLivre);
        nbLivres--;
    }
    else {
        cout << "[GB] Vous ne pouvez pas retirer le livre au code " << code << " de la bibliothèque " << nom <<
            " car il n'y a pas été trouvé" << endl;
    }

}


void Bibliothèque::changerTaillePrêts() {
    const int nouvelleTaille = tailleTableauPrêts*2;
    Prêt* nouveauTableau = new Prêt[nouvelleTaille];

    for(int i=0; i < nbPrêts; i++) {
        nouveauTableau[i] = prêts[i];
    }

    prêts = nouveauTableau;
    tailleTableauPrêts *= nouvelleTaille;
}

void Bibliothèque::ajouterPrêt(const int codeBibliothèquePropriétaire, const int codePropriétaire, const int nouveauCode) {
    Prêt p(codeBibliothèquePropriétaire, codePropriétaire, nouveauCode);

    if(nbPrêts == tailleTableauPrêts) {
        changerTaillePrêts();
    }

    prêts[nbPrêts] = p;
    nbPrêts++;

}

void Bibliothèque::retirerPrêt(const int codeLivre) {
    int prêtIndex = -1;

    for(int i=0; i < nbPrêts; i++) {
        if(prêts[i].getCodePrêt() == codeLivre) {
            prêtIndex = i;
        }
    }

    for(int i=prêtIndex; i < nbPrêts - 1; i++) {
        prêts[i] = prêts[i+1];
    }

    nbPrêts--;

}



void Bibliothèque::emprunterLivre(const int codeLivre) const {
    livres.emprunterLivre(codeLivre);
}


void Bibliothèque::rendreLivre(const int codeLivre) const {
    livres.rendreLivre(codeLivre);
}

// Option de la bibliothèque
void Bibliothèque::acheterLivre(Livre* livre) {
    //todo: vérifions que le livre est neuf (exception try catch)

    std:: cout << "[GB] La Bibliothèque " << nom << " achète le livre : " << livre->getTitre() << std::endl;
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

Livre* Bibliothèque::getLivre(const int codeLivre) const {
    Livre *résultat = livres.getLivre(codeLivre);

    if(résultat->getCode() != codeLivre) {
        cout << "[GB] La bibliothèque " << nom << " ne possède pas de livre avec le code " << codeLivre << endl;
    }

    return résultat;
}


Livre* Bibliothèque::getLivre(const string& isbn) const {
    Livre *résultat = livres.getLivre(isbn);

    if(résultat->getIsbn() != isbn) {
        cout << "[GB] La bibliothèque " << nom << " ne possède pas de livre avec l'isbn " << isbn << endl;
    }

    return résultat;

}

// Méthodes entre bibliothèques
void Bibliothèque::demanderLivre(Bibliothèque *bibliothèque, const string &isbn) {
    Livre* livre = bibliothèque->getLivre(isbn);

    // On vérifie que le livre est bien dans la bibliothèque à laquelle on fait la demande
    if(livre->getCode() != -1) {
        if(livre->getÉtat() == "libre") {
            // Le livre est libre donc on peut l'emprunter
            ajouterPrêt(bibliothèque->getCode(), livre->getCode(), maxCode);
            bibliothèque->retirerLivre(livre->getCode());
            ajouterLivre(livre);
        }
        else {
            cout << "[GB] La bibliothèque " << bibliothèque->getNom() << " possède le livre mais il a déjà été emprunté"
            << endl;
        }
    }
    else {
        cout << "[GB] La bibliothèque " << bibliothèque->getNom() << " ne possède pas ce livre" << endl;
    }

}

void Bibliothèque::terminerPrêt(Bibliothèque *bibliothèques, int nbBibliothèques, int codeLivre) {

    // Cherchons le prêt concerné par le codeLivre

    int i = 0;
    int prêtIndex = -1;
    while(i < nbPrêts && prêtIndex == -1){
        if(prêts[i].getCodePrêt() == codeLivre) {
            prêtIndex = i;
        }
        i++;
    }

    if(prêtIndex != -1) {
        // On rend donc le livre à son propriétaire
        Bibliothèque* propriétaire;

        i = 0;
        int bibliothèqueIndex = -1;
        while(i < nbBibliothèques && bibliothèqueIndex == -1) {
            if(bibliothèques[i].getCode() == prêts[prêtIndex].getPropriétaire()) {
                bibliothèqueIndex = i;
            }
            i++;
        }

        if(bibliothèqueIndex != -1) {
            Livre* livre = getLivre(codeLivre);

            if(livre->getCode() != -1 && livre->getÉtat() == "libre") {
                retirerLivre(codeLivre);
                retirerPrêt(codeLivre);

                bibliothèques[bibliothèqueIndex].ajouterLivre(livre);

                cout << "[GB] Le livre " << livre->getTitre() << " a bien été rendu à sa bibliothèque d'origine !" << endl;
                return;
            }
        }

    }

    cout << "[GB] Erreur lors de la restitution du livre au code : " << codeLivre << endl;
}


void Bibliothèque::supprimerLivre(const int codeLivre) {
    // Avant de confirmer la destruction du livre, on doit d'abord vérifier qu'il ne s'agit pas d'un prêt d'une autre
    // bibliothèque.

    int index = -1;
    int i = 0;
    while (i < nbPrêts && index == -1) {
        if(prêts[i].getCodePrêt() == codeLivre) {
            index = i;
        }
        i++;
    }

    if(index == -1) {
        retirerLivre(codeLivre);
    }
    else {
        cout << "[GB] Erreur le livre est un prêt, il ne peut pas être supprimé de la bibliothèque d'origine" << endl;
    }


}

