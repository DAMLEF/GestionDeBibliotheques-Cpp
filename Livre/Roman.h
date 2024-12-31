# ifndef ROMAN_H
# define ROMAN_H

# include "Livre.h"

class Roman final: public Livre {
    private:
        string genre;

    public:
        Roman(const string &isbn, int code, const string &auteur, const string &titre, const string& éditeur,
            const string& publicCible, const string& genre);

        // Getters
        const string& getGenre() const;


        void afficherLivre() const override;

};



# endif //ROMAN_H
