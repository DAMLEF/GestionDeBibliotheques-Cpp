# ifndef THÉÂTRE_H
# define THÉÂTRE_H


# include "Livre.h"


class Théâtre final: public Livre {
    private:
        int siècle;
    public:
        Théâtre(const string &isbn, int code, const string &auteur, const string &titre, const string& éditeur,
            const string& publicCible, int siècle);

        // Getters
        int getSiècle() const;


        void afficherLivre() const override;


};



# endif //THÉÂTRE_H
