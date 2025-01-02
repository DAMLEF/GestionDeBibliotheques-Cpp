# ifndef ADHÉRENT_H
# define ADHÉRENT_H


#include "Bibliothèque.h"

class Adhérent {
    private:
        string nom;
        string prénom;
        string adresse;

        int numéroAdhérent;
        Bibliothèque& bibliothèqueAdhérent;   //todo bibli ou int ?

        Livre* emprunts;
        int nombreEmprunts;
        int nombreEmpruntsRestants;

    public:

        Adhérent(Bibliothèque &b, const string &nom, const string &prénom, const string &adresse,
                 int numéroAdhérent, int nombreMaxEmprunts);

        void afficherAdhérent() const;



        int emprunterLivre(int codeLivre);
        int rendreLivre(int codeLivre);


        // Getters
        string getNom() const;
        string getPrénom() const;
        string getAdresse() const;

        int getNuméroAdhérent() const;

        int getNombreEmpruntsRestants() const;

};



# endif //ADHÉRENT_H
