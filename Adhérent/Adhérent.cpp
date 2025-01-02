# include "Adhérent.h"

Adhérent::Adhérent(Bibliothèque &b, const string &nom, const string &prénom, const string &adresse,
                   const int numéroAdhérent, const int nombreMaxEmprunts): bibliothèqueAdhérent(b) {
    this->nom = nom;
    this->prénom = prénom;
    this->adresse = adresse;

    this->numéroAdhérent = numéroAdhérent;
    this->bibliothèqueAdhérent = b;

    this->nombreEmpruntsRestants = nombreMaxEmprunts;
    this->emprunts = new Livre[nombreMaxEmprunts];
    this->nombreEmprunts = 0;
}

void Adhérent::afficherAdhérent() const {
    std::cout << "---------------------------------------------\n";
    std::cout << "Adhérent : "<< nom << " " << prénom << std::endl << std::endl;

    std::cout << "Nom           : " << nom << std::endl;
    std::cout << "Prénom        : " << prénom << std::endl;
    std::cout << "Adresse       : " << adresse << std::endl << std::endl;

    std::cout << "Bibliothèque  : " << bibliothèqueAdhérent.getNom() << std::endl;
    std::cout << "Nombre d'emprunts : " << nombreEmprunts << std::endl;
    std::cout << "Emprunts possible restants : " << nombreEmpruntsRestants << std::endl;
    std::cout << "---------------------------------------------\n";
}


int Adhérent::emprunterLivre(const int codeLivre) {
    if(this->nombreEmpruntsRestants > 0) {
        const Livre result = bibliothèqueAdhérent.getLivre(codeLivre);

        // On vérifie que le livre reçu est bien le bon (éviter le code d'erreur).
        if (result.getCode() == codeLivre) {
            if(result.getÉtat() == "libre") {   //todo: constante d'état ?
                emprunts[nombreEmprunts] = result;      //todo tester si c'est le même que dans la bdd
                nombreEmprunts++;
                nombreEmpruntsRestants--;
                bibliothèqueAdhérent.emprunterLivre(codeLivre); //todo est-ce que la bibliothèque change ?

                cout << "[GB] L'adhérent " << nom << " " << prénom <<" de la bibliothèque " << bibliothèqueAdhérent.getNom() <<
                    " a emprunté le livre au code : " << codeLivre << endl;

                return 0;
            }
            cout << "[GB] L'adhérent " << nom << " " << prénom << " de la bibliothèque " << bibliothèqueAdhérent.getNom() <<
                    " tente d'emprunter un livre qui n'est pas libre ! " << endl;
        }
        else {
            cout << "[GB] L'adhérent " << nom << " " << prénom << " de la bibliothèque " << bibliothèqueAdhérent.getNom() <<
                " tente d'emprunter un livre alors que le code " << codeLivre << "  est introuvable !" << endl;
        }

    }
    else {
        cout << "[GB] L'adhérent " << nom<< " " << prénom << " de la bibliothèque " << bibliothèqueAdhérent.getNom() <<
            " tente d'emprunter un livre alors qu'il n'a plus de crédit !" << endl;
    }

    return -1;
}


int Adhérent::rendreLivre(const int codeLivre) {
    int livreIndex = -1;
    int i = 0;

    while(livreIndex == -1 && i < nombreEmprunts) {
        if(emprunts[i].getCode() == codeLivre) {
            livreIndex = i;
        }
        i++;
    }

    if(livreIndex != -1) {
        bibliothèqueAdhérent.rendreLivre(codeLivre);

        // Le livre doit maintenant être supprimé du tableau
        for(int j=livreIndex; j < nombreEmprunts - 1; j++) {
            emprunts[j] = emprunts[j + 1];
        }

        nombreEmprunts--;
        nombreEmpruntsRestants++;

        cout << "[GB] L'adhérent " << nom << " " << prénom <<" de la bibliothèque " << bibliothèqueAdhérent.getNom() <<
            " rend le livre au code " << codeLivre << " à la bibliothèque" << endl;

        return 0;   // La fonction s'est éxécuté avec succès
    }

    cout << "[GB] Erreur : L'adhérent " << nom << " " << prénom <<" de la bibliothèque " << bibliothèqueAdhérent.getNom() <<
    " n'a pas pu rendre le livre au code  : " << codeLivre << endl;

    return -1;

}



string Adhérent::getNom() const {
    return nom;
}

string Adhérent::getPrénom() const {
    return prénom;
}

string Adhérent::getAdresse() const {
    return adresse;
}

int Adhérent::getNuméroAdhérent() const {
    return numéroAdhérent;
}

int Adhérent::getNombreEmpruntsRestants() const {
    return nombreEmpruntsRestants;
}
