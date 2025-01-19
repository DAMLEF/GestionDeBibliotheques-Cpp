# ifndef PRÊT_H
# define PRÊT_H


class Prêt {
    private:
        int propriétaireBCode;           // Code de la bibliothèque du propriétaire
        int codePrêt;                   // Code du livre chez la bibliothèque qui reçoit le livre
        int codePropriétaire;           // Code du livre chez son propriétaire
    public:
        Prêt();
        Prêt(int propriétaireLivreCode, int codePropriétaire, int codePrêt);

        // Getters
        int getCodePrêt() const;
        int getPropriétaire() const;
};



# endif //PRÊT_H
