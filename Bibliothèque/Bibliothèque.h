#ifndef BIBLIOTHÈQUE_H
#define BIBLIOTHÈQUE_H

#include "Livre.h"


class Bibliothèque {
    private:
        int code;

        string nom;
        string adresse;

        Livre* livres;
        int nbLivres;
        int max_size;   // Stocke la taille maximale que peut accueillir le tableau livres (pour réadapter en fonction des besoins de la bibliothèque)

        // Fonction interne
        void agrandirTableau();
        void ajouterLivre(Livre livre);

    public:
        Bibliothèque(int code, const string& nom, const string& adresse);

        void afficherBibliothèque() const;

        void afficherLivres() const;
        void afficherLivres(const string& catégorie) const;

        // Getters
        int getCode() const;

        const string & getNom() const;
        const string & getAdresse() const;


};



#endif //BIBLIOTHÈQUE_H
