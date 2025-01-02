# ifndef POÉSIE_H
# define POÉSIE_H


# include "Livre.h"


class Poésie final: public Livre {
    private:
        bool vers;
        bool prose;
    public:
        Poésie(const string& isbn, int code, const string &auteur, const string &titre, const string& éditeur,
            const string& publicCible, bool vers, bool prose);

        // Getters
        bool getVers() const;
        bool getProse() const;


        void afficherLivre() const override;

};



# endif //POÉSIE_H
