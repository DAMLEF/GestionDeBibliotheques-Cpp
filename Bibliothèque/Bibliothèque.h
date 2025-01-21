#ifndef BIBLIOTHÈQUE_H
#define BIBLIOTHÈQUE_H

# include "LivreLC.h"
# include "Prêt.h"


class Bibliothèque {
    private:
        int code;

        string nom;
        string adresse;

        LivreLC livres;
        int nbLivres;
        int maxCode;

        Prêt* prêts;
        int nbPrêts;
        int tailleTableauPrêts;


        // Fonction interne
        void ajouterLivre(Livre* livre);
        void retirerLivre(int codeLivre);

        void changerTaillePrêts();
        void ajouterPrêt(int codeBibliothèquePropriétaire, int codePropriétaire, int nouveauCode);
        void retirerPrêt(int codeLivre);


    public:
        Bibliothèque();
        Bibliothèque(int code, const string& nom, const string& adresse);

        void afficherBibliothèque() const;

        void afficherLivres();
        void afficherLivres(const string& catégorie);

        void afficherPrêts() const;

        void acheterLivre(Livre livre);
        void supprimerLivre(int codeLivre);

        // Méthodes en lien avec les adhérents
        void emprunterLivre(int codeLivre) const;
        void rendreLivre(int codeLivre) const;

        // Méthodes entre bibliothèques
        void demanderLivre(Bibliothèque& bibliothèque, const string& isbn);
        void terminerPrêt(Bibliothèque* bibliothèques, int nbBibliothèques, int codeLivre);

        // Getters
        int getCode() const;

        const string & getNom() const;
        const string & getAdresse() const;

        int getNbLivres() const;

        Livre* getLivre(const string& isbn) const;
        Livre* getLivre(int codeLivre) const;




};



#endif //BIBLIOTHÈQUE_H
