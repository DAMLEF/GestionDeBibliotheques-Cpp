# include "LivreLC.h"

LivreLC::LivreLC() {
    this->livre = new Livre();
    this->suivant = nullptr;
}

LivreLC::LivreLC(Livre* l) {
    this->livre = l;
    this->suivant = nullptr;
}

// Getters
LivreLC* LivreLC::getSuivant() const {
    return suivant;
}

Livre* LivreLC::getLivre() const {
    return livre;
}

Livre *LivreLC::getLivre(int codeLivre) const {
    const LivreLC *courant = this;

    while (courant != nullptr) {
        if(courant->getLivre()->getCode() == codeLivre) {
            return courant->getLivre();
        }
        courant = courant->getSuivant();
    }
    cout << "[GB] Erreur : Le livre n'a pas été trouvé dans la bibliothèque !" << endl;

    return new Livre();
}

Livre *LivreLC::getLivre(const string& isbn) const {
    const LivreLC *courant = this;

    while (courant != nullptr) {
        if(courant->getLivre()->getIsbn() == isbn) {
            return courant->getLivre();
        }
        courant = courant->getSuivant();
    }
    cout << "[GB] Erreur : Le livre n'a pas été trouvé dans la bibliothèque !" << endl;

    return new Livre();
}





bool LivreLC::estVide() const {
    if(this->suivant == nullptr && this->livre->getCode() == -1) {
        return true;
    }

    return false;
}


void LivreLC::afficherListe(){
    LivreLC* temp = this;

    if(estVide()) {
        return;
    }

    while (temp != nullptr) {
        temp->livre->afficherLivre();
        temp = temp->suivant;
    }

}

void LivreLC::afficherListe(const string &catégorie){
    LivreLC* temp = this;

    if(estVide()) {
        return;
    }

    while (temp != nullptr) {
        if(temp->livre->getCatégorie() == catégorie) {
            temp->livre->afficherLivre();
        }
        temp = temp->suivant;
    }

}


void LivreLC::setLivre(Livre* l) {
    livre = l;
}


int LivreLC::longueurRécursif() const {
    if(livre->getCode() == -1) {
        return 0;
    }

    if(suivant == nullptr) {
        return 1;
    }

    return 1 + suivant->longueurRécursif();


}

int LivreLC::longueur() const {
    int result = 1;
    LivreLC* temp = suivant;

    if(livre->getCode() == -1) {
        return 0;
    }

    while(temp != nullptr) {
        result++;
        temp = temp->suivant;
    }

    return result;

}


void LivreLC::ajouterLivre(Livre* l) {
    LivreLC* temp = suivant;
    auto précédent = this;

    if(livre->getCode() == -1) {
        setLivre(l);
        return;
    }

    while(temp != nullptr) {
        précédent = temp;
        temp = temp->suivant;
    }

    temp = new LivreLC(l);

    précédent->suivant = temp;


}


void LivreLC::retirerLivre(int codeLivre) {
    LivreLC* temp = suivant;
    LivreLC* précédent = this;

    if(this->livre->getCode() == codeLivre) {
        // Le livre se situe en tête de liste
        if(temp != nullptr) {
            livre = suivant->livre;
            suivant = suivant->suivant;
        }
        else {
            livre = new Livre();
        }

        return;
    }

    while(temp != nullptr && temp->livre->getCode() != codeLivre){
        précédent = temp;
        temp = temp->suivant;
    }

    if(temp == nullptr) {
        cout << "[GB] Impossible de retirer le livre de la liste (le code n'a pas été trouvé) !" << endl;
        return;
    }

    if(temp->livre->getCode() == codeLivre) {
        précédent->suivant = temp->suivant;
    }


}


void LivreLC::emprunterLivre(const int codeLivre) const {
    const LivreLC* courant = this;

    while(courant != nullptr) {
        if(courant->getLivre()->getCode() == codeLivre) {
            if(courant->getLivre()->getÉtat() == "libre") {
                courant->getLivre()->setÉtat("emprunté");
            }
            else {
                cout << "[GB] Erreur : Vous ne pouvez pas emprunté un livre qui n'est pas libre !" << endl;
            }
            return;
        }

        courant = courant->getSuivant();
    }

    cout << "[GB] Erreur : Vous ne pouvez pas emprunté ce livre car le code n'existe pas dans la bibliothèque !" << endl;

}

void LivreLC::rendreLivre(const int codeLivre) const {
    const LivreLC* courant = this;

    while(courant != nullptr) {
        if(courant->getLivre()->getCode() == codeLivre) {
            if(courant->getLivre()->getÉtat() == "emprunté") {
                courant->getLivre()->setÉtat("libre");
            }
            else {
                cout << "[GB] Erreur : Vous ne pouvez pas rendre un livre qui n'est pas emprunté !" << endl;
            }
            return;
        }

        courant = courant->getSuivant();
    }

    cout << "[GB] Erreur : Vous ne pouvez pas rendre ce livre car le code n'existe pas dans la bibliothèque !" << endl;

}


