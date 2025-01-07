# ifndef PRÊT_H
# define PRÊT_H

# include "Bibliothèque.h"


class Prêt {
    private:
        Bibliothèque& propriétaire;
        int codePrêt;                   // Code du livre chez la bibliothèque qui reçoit le livre
        int codePropriétaire;           // Code du livre chez son propriétaire
    public:
        Prêt(Bibliothèque& propriétaireLivre, int codePropriétaire, int codePrêt);
};



# endif //PRÊT_H
