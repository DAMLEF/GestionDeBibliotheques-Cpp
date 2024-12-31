# include <iostream>
# include <locale>

// Importation des bibliothèques
# include "Livre.h"

int main() {
    system("chcp 65001");  // Change l'encodage de la console en UTF-8

    const Livre livreHarryPotter2(" 2-07-052455-8", 1, "JK Rowling", "Harry Potter et la Chambre des Secrets",
                                  "Folio Junior", "Jeunesse", "Fantastique");

    livreHarryPotter2.showLivre();

    return 0;
}