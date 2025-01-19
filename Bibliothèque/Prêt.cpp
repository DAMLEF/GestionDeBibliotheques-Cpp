# include "Prêt.h"

Prêt::Prêt() {
    this->propriétaireBCode = -1;
    this->codePropriétaire = -1;
    this->codePrêt = -1;
}

Prêt::Prêt(int propriétaireLivreCode, int codePropriétaire, int codePrêt) {
    this->propriétaireBCode = propriétaireLivreCode;
    this->codePropriétaire = codePropriétaire;
    this->codePrêt = codePrêt;
}

int Prêt::getCodePrêt() const {
    return codePrêt;
}

int Prêt::getPropriétaire() const {
    return propriétaireBCode;
}
