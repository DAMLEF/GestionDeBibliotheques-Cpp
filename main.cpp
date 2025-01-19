// Importation des bibliothèques
# include "BD.h"
# include "Poésie.h"
# include "Album.h"
# include "Théâtre.h"
# include "Roman.h"

# include "LivreLC.h"

# include "Bibliothèque.h"

#include "Adhérent.h"

// -------------------------------- //

extern const string poésieVersEtProse;  //todo: à voir ?


int main() {
    system("chcp 65001");  // Change l'encodage de la console en UTF-8

    Bibliothèque bnf_fm(0, "Bibliothèque nationale de France : site François-Mitterrand", "Quai François Mauriac, Paris, France");

    Adhérent  a_cb(bnf_fm, "Charles", "Baudelaire", "22 Quai de Béthune, Paris, France", 0, 20);


    Livre *livreHarryPotter2 = new Livre(" 2-07-052455-8", 3, "JK Rowling", "Harry Potter et la Chambre des Secrets",
                                         "Folio Junior", "Jeunesse", "Fantastique");
    Roman* LivreTest = new Roman(" 2-07-052455-8", 5, "JK Rowling", "Harry Potter et la Chambre des Secrets",
                                  "Folio Junior", "Jeunesse", "Fantastique");

    Roman* Test2 = new Roman(" 2-07-052455-8", 8, "JK Rowling", "Harry Potter et la Chambre des Secrets",
                              "Folio Junior", "Jeunesse", "Fantastique");


    // Test classe Bibliothèque

    bnf_fm.afficherBibliothèque();

    bnf_fm.acheterLivre(livreHarryPotter2);
    bnf_fm.acheterLivre(LivreTest);
    bnf_fm.acheterLivre(livreHarryPotter2);


    bnf_fm.afficherLivres("Roman");
    bnf_fm.afficherLivres();

    // Test classe Adhérent

    a_cb.afficherAdhérent();

    a_cb.emprunterLivre(2);
    a_cb.emprunterLivre(2); // On tente d'emprunter le même livre

    a_cb.afficherAdhérent(); // Vérifions son état
    bnf_fm.afficherLivres(); // Vérifions l'état de la bibliothèque

    a_cb.rendreLivre(1);    // Erreur : Il ne possède pas le livre.
    a_cb.rendreLivre(2);    // Il rend le seul livre qu'il possède

    bnf_fm.afficherLivres();    // On vérifie que le livre est de nouveau libre

    LivreLC lc;

    lc.ajouterLivre(LivreTest);
    lc.ajouterLivre(livreHarryPotter2);
    lc.ajouterLivre(Test2);

    //lc.afficherListe();

    lc.retirerLivre(5);

    lc.afficherListe();


    return 0;
}