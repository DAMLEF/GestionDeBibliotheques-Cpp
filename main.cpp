// Importation des bibliothèques
# include "BD.h"
# include "Poésie.h"
# include "Album.h"
# include "Théâtre.h"
# include "Roman.h"

extern const string poésieVersEtProse;  //todo: à voir ?


int main() {
    system("chcp 65001");  // Change l'encodage de la console en UTF-8

    const Livre livreHarryPotter2(" 2-07-052455-8", 1, "JK Rowling", "Harry Potter et la Chambre des Secrets",
                                  "Folio Junior", "Jeunesse", "Fantastique");

    const Roman LivreTest(" 2-07-052455-8", 1, "JK Rowling", "Harry Potter et la Chambre des Secrets",
                                  "Folio Junior", "Jeunesse", "Fantastique");

    //livreHarryPotter2.afficherLivre();
    LivreTest.afficherLivre();

    return 0;
}