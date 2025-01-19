# ifndef LIVRES_LC_H
# define LIVRES_LC_H

# include "Livre.h"


class LivreLC {
    private:
        Livre* livre;
        LivreLC* suivant;

    public:
        LivreLC();
        explicit LivreLC(Livre* l);

        bool estVide() const;

        int longueur() const;
        int longueurRécursif() const;

        void ajouterLivre(Livre* l);

        void retirerLivre(int codeLivre);

        void afficherListe();
        void afficherListe(const string &catégorie);

        void emprunterLivre(int codeLivre) const;
        void rendreLivre(int codeLivre) const;

        // Getters
        LivreLC* getSuivant() const;
        Livre* getLivre() const;
        Livre* getLivre(int codeLivre) const;
        Livre* getLivre(const string& isbn) const;



        // Setters
        void setLivre(Livre* l);

};



# endif //LIVRES_LC_H
