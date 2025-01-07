# ifndef LIVRE_H
# define LIVRE_H

# include <iostream>
# include <string>

using namespace std;

class Livre {
    private:
        string isbn;
        int code;

        string auteur;
        string titre;
        string éditeur;
        string publicCible;
        string catégorie;

        string état;
    public:
        Livre();
        Livre(const string &isbn, int code, const string &auteur, const string &titre, const string& éditeur,
            const string& publicCible, const string& catégorie);

        virtual void afficherLivre() const;

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



        virtual ~Livre() = default;
};



# endif //LIVRE_H
