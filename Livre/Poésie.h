# ifndef POÉSIE_H
# define POÉSIE_H


# include "Livre.h"


class Poésie final: public Livre {
    private:
        string indicateur;
    public:
        Poésie(const string& isbn, int code, const string &auteur, const string &titre, const string& éditeur,
            const string& publicCible, const string& indicateur);

        // Getters
        const string& getIndicateur() const;


        void afficherLivre() const override;

};



# endif //POÉSIE_H
