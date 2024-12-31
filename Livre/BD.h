# ifndef BD_H
# define BD_H

# include "Livre.h"


class BD final : public Livre {
    private:
        string dessinateur;

    public:
        BD(const string& isbn, int code, const string &auteur, const string &titre, const string& éditeur,
            const string& publicCible, const string& dessinateur);

        // Getters
        const string& getDessinateur() const;


        void afficherLivre() const override;

};



# endif //BD_H
