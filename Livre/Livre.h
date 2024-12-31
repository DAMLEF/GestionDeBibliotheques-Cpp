#ifndef LIVRE_H
#define LIVRE_H

#include <string>

using namespace std;

class Livre {
    private:
        string isbn;
        int code;

        string auteur;  //todo: const ?
        string titre;
        string éditeur;
        string publicCible;
        string catégorie;

        string état;
    public:
        Livre(const string &isbn, int code, const string &auteur, const string &titre, const string& éditeur, const string& publicCible, const string& catégorie);

        void showLivre() const;

        // Getters
        const string& getIsbn() const;
        int getCode() const;

        const string& getAuteur() const;
        const string& getTitre() const;
        const string& getÉditeur() const;
        const string& getPublicCible() const;
        const string& getCatégorie() const;

        const string& getÉtat() const;

        // Setters
        void setCode(int code);

        void setÉtat(const string& état);
};



#endif //LIVRE_H
