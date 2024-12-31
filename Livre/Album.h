# ifndef ALBUM_H
# define ALBUM_H


# include "Livre.h"


class Album final: public Livre {
    private:
        bool photos;
        bool dessins;
    public:
        Album(const string &isbn, int code, const string &auteur, const string &titre, const string& éditeur,
            const string& publicCible, bool photos, bool dessins);

        // Getters
        bool getPhotos() const;
        bool getDessins() const;


        void afficherLivre() const override;

};



#endif //ALBUM_H
