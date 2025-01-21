// Importation des bibliothèques
# include "BD.h"
# include "Poésie.h"
# include "Album.h"
# include "Théâtre.h"
# include "Roman.h"

# include "LivreLC.h"

# include "SaisieInvalide.h"

# include "Bibliothèque.h"

#include "Adhérent.h"

#include <thread>
#include <chrono> // Pour les durées
// -------------------------------- //



// Utilisation pour le bien être visuel de l'UI.
void pauseProgramme(const double secondes) {
    // Utilisation de chrono pour définir la durée
    this_thread::sleep_for(chrono::duration<double>(secondes));
}


int main() {
    system("chcp 65001");  // Change l'encodage de la console en UTF-8



    // LIVRES
    auto* livres = new Livre[150];
    int nbLivres = 25;

    // Roman (différents genres)
    Roman livre16("978-2-07-075902-6", 16, "Stendhal", "Le Rouge et le Noir",
                     "Classiques Garnier", "Adultes", "Roman de mœurs");
    Roman livre17("978-2-07-075903-3", 17, "Marguerite Yourcenar", "Mémoires d'Hadrien",
                     "Gallimard", "Adultes", "Roman-mémoires");
    Roman livre18("978-2-07-075904-0", 18, "Alexandre Dumas", "Les Trois Mousquetaires",
                     "Classiques Garnier", "Tous publics", "Roman de chevalerie");
    Roman livre19("978-2-07-075905-7", 19, "Marcel Proust", "Du côté de chez Swann",
                      "Gallimard", "Adultes", "Nouveau roman");
    Roman livre20("978-2-07-075906-4", 20, "Jack London", "L'Appel de la forêt",
                      "Folio Junior", "Jeunesse", "Roman animalier");
    Roman livre21("978-2-07-075907-1", 21, "Arthur Conan Doyle", "Sherlock Holmes : Une étude en rouge",
                      "Hachette", "Adultes", "Roman policier");
    Roman livre22("978-2-07-075908-8", 22, "Ian Fleming", "James Bond : Casino Royale",
                      "Gallimard", "Adultes", "Roman d'espionnage");
    Roman livre23("978-2-07-075909-5", 23, "Antoine de Saint-Exupéry", "Le Petit Prince",
                     "Gallimard", "Tous publics", "Roman philosophique");
    Roman livre24("978-2-07-075910-1", 24, "Jules Verne", "Voyage au centre de la Terre",
                      "Hachette", "Tous publics", "Roman d'aventures");
    Roman livre25("978-2-07-075911-8", 25, "Charlotte Brontë", "Jane Eyre",
                            "Penguin Classics", "Adultes", "Roman d'amour");

    // Théâtre
    Théâtre livre26("978-2-07-075912-5", 26, "William Shakespeare", "Hamlet",
                      "Penguin Classics", "Adultes", 16);
    Théâtre livre27("978-2-07-075913-2", 27, "Corneille", "Le Cid",
                      "Gallimard", "Scolaire", 17);
    Théâtre livre28("978-2-07-075914-9", 28, "Anton Tchekhov", "La Cerisaie",
                             "Gallimard", "Adultes", 19);

    // Poésie
    Poésie livre29("978-2-07-075915-6", 29, "Paul Éluard", "Liberté",
                     "Gallimard", "Adultes", true, false);
    Poésie livre30("978-2-07-075916-3", 30, "Guillaume Apollinaire", "Alcools",
                     "Folio", "Adultes", false, true);
    Poésie livre31("978-2-07-075917-0", 31, "Victor Hugo", "Les Contemplations",
                            "Gallimard", "Adultes", true, true);

    // BD
    BD livre32("978-2-07-075918-7", 32, "René Goscinny", "Astérix le Gaulois",
                 "Dargaud", "Tous publics", "Albert Uderzo");
    BD livre33("978-2-07-075919-4", 33, "Jean Van Hamme", "Thorgal : La Magicienne Trahie",
                 "Le Lombard", "Adultes", "Grzegorz Rosiński");
    BD livre34("978-2-07-075920-0", 34, "Marjane Satrapi", "Persepolis",
                        "L'Association", "Adultes", "Marjane Satrapi");

    // Album
    Album livre35("978-2-07-075921-7", 35, "Steve McCurry", "Une vie en images",
                     "ArtBooks", "Adultes", true, false);
    Album livre36("978-2-07-075922-4", 36, "Claude Monet", "Monet et l'impressionnisme",
                     "ArtBooks", "Tous publics", false, true);
    Album livre37("978-2-07-075923-1", 37, "Louvre", "L'Art du Louvre : Collections en images",
                            "Gallimard", "Tous publics", true, true);

    // Autres genres de Roman
    Roman livre38("978-2-07-075924-8", 38, "Emile Zola", "Germinal",
                           "Gallimard", "Adultes", "Roman social");
    Roman livre39("978-2-07-075925-5", 39, "Daniel Defoe", "Robinson Crusoé",
                     "Penguin Classics", "Adultes", "Roman d'aventures");
    Roman livre40("978-2-07-075926-2", 40, "François Rabelais", "Gargantua",
                            "Classiques Garnier", "Adultes", "Roman picaresque");


    livres[0] = livre16;
    livres[1] = livre17;
    livres[2] = livre18;
    livres[3] = livre19;
    livres[4] = livre20;
    livres[5] = livre21;
    livres[6] = livre22;
    livres[7] = livre23;
    livres[8] = livre24;
    livres[9] = livre25;
    livres[10] = livre26;
    livres[11] = livre27;
    livres[12] = livre28;
    livres[13] = livre29;
    livres[14] = livre30;
    livres[15] = livre31;
    livres[16] = livre32;
    livres[17] = livre33;
    livres[18] = livre34;
    livres[19] = livre35;
    livres[20] = livre36;
    livres[21] = livre37;
    livres[22] = livre38;
    livres[23] = livre39;
    livres[24] = livre40;


    // BIBLIOTHÈQUES
    Bibliothèque* bibliothèques = new Bibliothèque[150];
    int nbBibliothèques = 27;


    // Bibliothèques pour les grandes villes françaises
    Bibliothèque bm_paris(0, "Bibliothèque nationale de France : site François-Mitterrand", "Quai François Mauriac, Paris, France");
    Bibliothèque bm_lyon(1, "Bibliothèque municipale de Lyon", "30 Boulevard Marius Vivier-Merle, Lyon, France");
    Bibliothèque bm_marseille(2, "Bibliothèque de l'Alcazar", "58 Cours Belsunce, Marseille, France");
    Bibliothèque bm_toulouse(3, "Bibliothèque d'Étude et du Patrimoine de Toulouse", "1 Rue de Périgord, Toulouse, France");
    Bibliothèque bm_lille(4, "Bibliothèque municipale de Lille", "80 Rue des Canonniers, Lille, France");
    Bibliothèque bm_nantes(5, "Médiathèque Jacques Demy", "15 Quai de la Fosse, Nantes, France");
    Bibliothèque bm_strasbourg(6, "Bibliothèque nationale et universitaire de Strasbourg", "6 Place de la République, Strasbourg, France");
    Bibliothèque bm_bordeaux(7, "Bibliothèque Mériadeck", "85 Cours du Maréchal Juin, Bordeaux, France");
    Bibliothèque bm_nice(8, "Bibliothèque Louis Nucéra", "2 Place Yves Klein, Nice, France");
    Bibliothèque bm_rennes(9, "Les Champs Libres - Bibliothèque de Rennes Métropole", "10 Cours des Alliés, Rennes, France");

    // Bibliothèques supplémentaires dans d'autres villes
    Bibliothèque bm_grenoble(10, "Bibliothèque municipale de Grenoble", "12 Boulevard Maréchal Lyautey, Grenoble, France");
    Bibliothèque bm_tours(11, "Bibliothèque municipale de Tours", "2 Avenue André Malraux, Tours, France");
    Bibliothèque bm_avignon(12, "Bibliothèque Ceccano", "2 Bis Rue Laboureur, Avignon, France");
    Bibliothèque bm_clermont(13, "Bibliothèque municipale de Clermont-Ferrand", "3 Rue Abbé Girard, Clermont-Ferrand, France");
    Bibliothèque bm_caen(14, "Bibliothèque Alexis de Tocqueville", "15 Quai François Mitterrand, Caen, France");

    // Bonus : Bibliothèques dans des villes choisies
    Bibliothèque bm_biarritz(15, "Médiathèque de Biarritz", "2 Rue Ambroise Paré, Biarritz, France");
    Bibliothèque bm_annecy(16, "Bibliothèque Bonlieu", "1 Rue Jean Jaurès, Annecy, France");
    Bibliothèque bm_ajaccio(17, "Bibliothèque Patrimoniale Fesch", "50 Rue Cardinal Fesch, Ajaccio, France");

    // Bibliothèques pour les DOM-TOM
    Bibliothèque bm_guadeloupe(18, "Bibliothèque multimédia Raoul Georges Nicolo", "Rue Alfred Lumière, Pointe-à-Pitre, Guadeloupe");
    Bibliothèque bm_martinique(19, "Bibliothèque Schœlcher", "Rue de la Liberté, Fort-de-France, Martinique");
    Bibliothèque bm_guyane(20, "Bibliothèque Franconie", "Avenue du Général de Gaulle, Cayenne, Guyane");
    Bibliothèque bm_reunion(21, "Bibliothèque intercommunale Alain Lorraine", "Rue du Père Favron, Saint-Pierre, Réunion");
    Bibliothèque bm_mayotte(22, "Médiathèque de Passamainty", "Passamainty, Mamoudzou, Mayotte");
    Bibliothèque bm_nouvelle_caledonie(23, "Bibliothèque Bernheim", "Avenue du Maréchal Foch, Nouméa, Nouvelle-Calédonie");
    Bibliothèque bm_polynesie(24, "Bibliothèque de la Maison de la Culture", "Avenue du Prince Hīnoi, Papeete, Polynésie française");
    Bibliothèque bm_saint_pierre_et_miquelon(25, "Médiathèque municipale de Saint-Pierre", "Rue Albert Briand, Saint-Pierre, Saint-Pierre-et-Miquelon");
    Bibliothèque bm_wallisetfutuna(26, "Bibliothèque publique de Mata-Utu", "Place des Chevaliers, Mata-Utu, Wallis-et-Futuna");

    bibliothèques[0] = bm_paris;
    bibliothèques[1] = bm_lyon;
    bibliothèques[2] = bm_marseille;
    bibliothèques[3] = bm_toulouse;
    bibliothèques[4] = bm_lille;
    bibliothèques[5] = bm_nantes;
    bibliothèques[6] = bm_strasbourg;
    bibliothèques[7] = bm_bordeaux;
    bibliothèques[8] = bm_nice;
    bibliothèques[9] = bm_rennes;
    bibliothèques[10] = bm_grenoble;
    bibliothèques[11] = bm_tours;
    bibliothèques[12] = bm_avignon;
    bibliothèques[13] = bm_clermont;
    bibliothèques[14] = bm_caen;
    bibliothèques[15] = bm_biarritz;
    bibliothèques[16] = bm_annecy;
    bibliothèques[17] = bm_ajaccio;
    bibliothèques[18] = bm_guadeloupe;
    bibliothèques[19] = bm_martinique;
    bibliothèques[20] = bm_guyane;
    bibliothèques[21] = bm_reunion;
    bibliothèques[22] = bm_mayotte;
    bibliothèques[23] = bm_nouvelle_caledonie;
    bibliothèques[24] = bm_polynesie;
    bibliothèques[25] = bm_saint_pierre_et_miquelon;
    bibliothèques[26] = bm_wallisetfutuna;



    Adhérent** adhérents = new Adhérent*[150];
    int nbAdhérents = 38;

    // Adhérents pour Paris (Bibliothèque nationale de France : site François-Mitterrand)
    Adhérent* a_cb = new Adhérent(bibliothèques[0], "Charles", "Baudelaire", "22 Quai de Béthune, Paris, France", 0, 20);
    Adhérent* a_vm = new Adhérent(bibliothèques[0], "Victor", "Hugo", "Place des Vosges, Paris, France", 1, 15);

    // Adhérents pour Lyon (Bibliothèque municipale de Lyon)
    Adhérent* a_pl = new Adhérent(bibliothèques[1], "Paul", "Lafargue", "10 Quai Claude Bernard, Lyon, France", 2, 10);
    Adhérent* a_jr = new Adhérent(bibliothèques[1], "Jean", "Racine", "14 Rue de la République, Lyon, France", 3, 5);

    // Adhérents pour Marseille (Bibliothèque de l'Alcazar)
    Adhérent* a_av = new Adhérent(bibliothèques[2], "Albert", "Camus", "15 Boulevard Longchamp, Marseille, France", 4, 12);
    Adhérent* a_pm = new Adhérent(bibliothèques[2], "Paul", "Mistral", "10 Rue Saint-Ferréol, Marseille, France", 5, 8);

    // Adhérents pour Toulouse (Bibliothèque d'Étude et du Patrimoine de Toulouse)
    Adhérent* a_jj = new Adhérent(bibliothèques[3], "Jean", "Jaurès", "1 Place du Capitole, Toulouse, France", 6, 10);
    Adhérent* a_cp = new Adhérent(bibliothèques[3], "Claude", "Nougaro", "14 Rue Gambetta, Toulouse, France", 7, 6);

    // Adhérents pour Lille (Bibliothèque municipale de Lille)
    Adhérent* a_em = new Adhérent(bibliothèques[4], "Émile", "Zola", "12 Rue du Molinel, Lille, France", 8, 15);
    Adhérent* a_fp = new Adhérent(bibliothèques[4], "Félix", "Pottier", "8 Rue de la Monnaie, Lille, France", 9, 7);

    // Adhérents pour Nantes (Médiathèque Jacques Demy)
    Adhérent* a_js = new Adhérent(bibliothèques[5], "Jules", "Verne", "4 Quai de la Fosse, Nantes, France", 10, 20);
    Adhérent* a_cm = new Adhérent(bibliothèques[5], "Claire", "Martin", "16 Rue Kervégan, Nantes, France", 11, 5);

    // Adhérents pour Strasbourg (Bibliothèque nationale et universitaire de Strasbourg)
    Adhérent* a_gr = new Adhérent(bibliothèques[6], "Gérard", "de Nerval", "10 Place Kléber, Strasbourg, France", 12, 15);
    Adhérent* a_mp = new Adhérent(bibliothèques[6], "Marie", "Curie", "8 Rue Goethe, Strasbourg, France", 13, 10);

    // Adhérents pour Bordeaux (Bibliothèque Mériadeck)
    Adhérent* a_mm = new Adhérent(bibliothèques[7], "Michel", "de Montaigne", "85 Cours du Maréchal Juin, Bordeaux, France", 14, 15);
    Adhérent* a_fp2 = new Adhérent(bibliothèques[7], "François", "Peyrou", "3 Place Pey-Berland, Bordeaux, France", 15, 10);

    // Adhérents pour Nice (Bibliothèque Louis Nucéra)
    Adhérent* a_af = new Adhérent(bibliothèques[8], "Auguste", "Flaubert", "10 Promenade des Anglais, Nice, France", 16, 8);
    Adhérent* a_lc = new Adhérent(bibliothèques[8], "Louis", "Carroll", "14 Rue de France, Nice, France", 17, 12);

    // Adhérents pour Rennes (Les Champs Libres - Bibliothèque de Rennes Métropole)
    Adhérent* a_rv = new Adhérent(bibliothèques[9], "René", "Viel", "10 Cours des Alliés, Rennes, France", 18, 15);
    Adhérent* a_mc = new Adhérent(bibliothèques[9], "Marguerite", "Duras", "5 Rue Saint-Michel, Rennes, France", 19, 7);

    // Adhérents pour les DOM-TOM

    // Guadeloupe
    Adhérent* a_jm = new Adhérent(bibliothèques[18], "Jean", "Médecin", "Rue Alfred Lumière, Pointe-à-Pitre, Guadeloupe", 20, 10);
    Adhérent* a_es = new Adhérent(bibliothèques[18], "Émilie", "Saintonge", "5 Rue de la Liberté, Pointe-à-Pitre, Guadeloupe", 21, 5);

    // Martinique
    Adhérent* a_fl = new Adhérent(bibliothèques[19], "Frantz", "Fanon", "Rue de la Liberté, Fort-de-France, Martinique", 22, 12);
    Adhérent* a_mc2 = new Adhérent(bibliothèques[19], "Marie", "Condé", "7 Rue Perrinon, Fort-de-France, Martinique", 23, 8);

    // Guyane
    Adhérent* a_ac = new Adhérent(bibliothèques[20], "André", "Césaire", "Avenue du Général de Gaulle, Cayenne, Guyane", 24, 10);
    Adhérent* a_ec = new Adhérent(bibliothèques[20], "Éric", "Chalumeau", "14 Rue Rouget, Cayenne, Guyane", 25, 6);

    // Réunion
    Adhérent* a_jl = new Adhérent(bibliothèques[21], "Jean", "Lafontaine", "Rue du Père Favron, Saint-Pierre, Réunion", 26, 20);
    Adhérent* a_cm2 = new Adhérent(bibliothèques[21], "Caroline", "Maréchal", "12 Rue du Port, Saint-Pierre, Réunion", 27, 15);

    // Mayotte
    Adhérent* a_mk = new Adhérent(bibliothèques[22], "Mohamed", "Karim", "Passamainty, Mamoudzou, Mayotte", 28, 5);
    Adhérent* a_lm = new Adhérent(bibliothèques[22], "Laura", "Massoud", "3 Rue des Cocotiers, Mamoudzou, Mayotte", 29, 8);

    // Nouvelle-Calédonie
    Adhérent* a_pm2 = new Adhérent(bibliothèques[23], "Pierre", "Merle", "Avenue du Maréchal Foch, Nouméa, Nouvelle-Calédonie", 30, 10);
    Adhérent* a_je = new Adhérent(bibliothèques[23], "Jacques", "Etoile", "2 Rue des Érables, Nouméa, Nouvelle-Calédonie", 31, 7);

    // Polynésie française
    Adhérent* a_tn = new Adhérent(bibliothèques[24], "Tahiti", "Nui", "Avenue du Prince Hīnoi, Papeete, Polynésie française", 32, 12);
    Adhérent* a_mp2 = new Adhérent(bibliothèques[24], "Moea", "Poe", "Rue des Fleurs, Papeete, Polynésie française", 33, 8);

    // Saint-Pierre-et-Miquelon
    Adhérent* a_c = new Adhérent(bibliothèques[25], "Christophe", "Garnier", "Rue Albert Briand, Saint-Pierre, Saint-Pierre-et-Miquelon", 34, 10);
    Adhérent* a_em2 = new Adhérent(bibliothèques[25], "Elisabeth", "Morin", "Rue des Navigateurs, Saint-Pierre, Saint-Pierre-et-Miquelon", 35, 7);

    // Wallis-et-Futuna
    Adhérent* a_wa = new Adhérent(bibliothèques[26], "Wane", "Futuna", "Place des Chevaliers, Mata-Utu, Wallis-et-Futuna", 36, 12);
    Adhérent* a_ja = new Adhérent(bibliothèques[26], "Joaquim", "Alonso", "3 Rue de l'Église, Mata-Utu, Wallis-et-Futuna", 37, 6);


    adhérents[0] = a_cb;
    adhérents[1] = a_vm;
    adhérents[2] = a_pl;
    adhérents[3] = a_jr;
    adhérents[4] = a_av;
    adhérents[5] = a_pm;
    adhérents[6] = a_jj;
    adhérents[7] = a_cp;
    adhérents[8] = a_em;
    adhérents[9] = a_fp;
    adhérents[10] = a_js;
    adhérents[11] = a_cm;
    adhérents[12] = a_gr;
    adhérents[13] = a_mp;
    adhérents[14] = a_mm;
    adhérents[15] = a_fp2;
    adhérents[16] = a_af;
    adhérents[17] = a_lc;
    adhérents[18] = a_rv;
    adhérents[19] = a_mc;
    adhérents[20] = a_jm;
    adhérents[21] = a_es;
    adhérents[22] = a_fl;
    adhérents[23] = a_mc2;
    adhérents[24] = a_ac;
    adhérents[25] = a_ec;
    adhérents[26] = a_jl;
    adhérents[27] = a_cm2;
    adhérents[28] = a_mk;
    adhérents[29] = a_lm;
    adhérents[30] = a_pm2;
    adhérents[31] = a_je;
    adhérents[32] = a_tn;
    adhérents[33] = a_mp2;
    adhérents[34] = a_c;
    adhérents[35] = a_em2;
    adhérents[36] = a_wa;
    adhérents[37] = a_ja;




    // Interface utilisateur :
    int choix = -1;

    int adhérentCourant = -1;
    int bibliothèqueCourant = -1;
    int bibliothèqueDemande = -1;

    int index = 0;


        // Définition des variables qui seront nécessaire selon le choix de l'utilisateur

            // Création de livres
    Livre* livre;
    string nomLivre;
    string nomAuteurLivre;
    string isbnLivre;
    string éditeurLivre;
    string publicCibleLivre;
    string genreLivre;
    int siècleLivre;
    string dessinateurLivre;
    int versLivre;
    int proseLivre;
    int dessinsLivre;
    int photosLivre;

            // Création d'un adhérent
    int bibliothèqueAdhérent;
    string nomAdhérent;
    string prénomAdhérent;
    string adresseAdhérent;
    int nombreEmpruntsAdhérent;

        // Création d'une bibliothèque
    string nomBibliothèque;
    string adresseBibliothèque;

        // Achat de livre
    string titreLivre;
    Livre achatLivre;

        // Demande de livre
    string isbnLivreDemande;




    cout << "/ --------------------------------------------------------- / " << endl;
    cout << " Bienvenue sur le gestionnaire de bibliothèques en C++ " << endl;
    cout << "(fait par Timothée S et Damien L)" << endl;
    cout << "/ --------------------------------------------------------- / " << endl;

    pauseProgramme(2.);

    while(choix != 7) {

        cout << "Vous pouvez effectuer un tas d'actions parmis celles proposée ci-dessous :" << endl;
        pauseProgramme(0.3);

        cout << " 1. Gérer les bibliothèques" << endl;
        cout << " 2. Gérer les adhérents" << endl;
        cout << " 3. Ajouter une bibliothèque" << endl;
        cout << " 4. Ajouter un adhérent" << endl;
        cout << " 5. Consulter les livres (livres présent dans la BDD)" << endl;
        cout << " 6. Ajouter un livre" << endl;
        cout << " 7. Éteindre l'application" << endl;

        cin >> choix;;

        if(cin.fail()) {
            cin.clear();
            choix = -1;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(choix==1){
            cout << "Gestion des bibliothèques" << endl;
            choix = -1;

            while (choix != 3) {
                cout << "Vous pouvez effectuer un tas d'actions parmis celles proposée ci-dessous :" << endl;
                cout << " 1. Choisir une bibliothèque" << endl;
                cout << " 2. Afficher les bibliothèques" << endl;
                cout << " 3. Retour au menu" << endl;

                cin >> choix;

                if(cin.fail()) {
                    cin.clear();
                    choix = -1;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(choix == 1) {
                    cout << "Choisissez une bibliothèque (ID: nombre) : " << endl;
                    cin >> bibliothèqueCourant;
                    choix = -1;
                    while(choix != 7 && bibliothèqueCourant > -1 && bibliothèqueCourant < nbBibliothèques) {
                        cout << "(Bibliothèque " << bibliothèques[bibliothèqueCourant].getNom() <<
                                ") Vous pouvez effectuer un tas d'actions parmis celles proposée ci-dessous :" << endl;

                        cout << " 1. Acheter un livre" << endl;
                        cout << " 2. Supprimer un livre" << endl;
                        cout << " 3. Demander un livre à une autre bibliothèque" << endl;
                        cout << " 4. Rendre un prêt à sa bibliothèque d'origine" << endl;
                        cout << " 5. Afficher les livres de la bibliothèque" << endl;
                        cout << " 6. Afficher les prêts de la bibliothèque (d'autres bibliothèques)" << endl;
                        cout << " 7. Retour au menu" << endl;

                        cin >> choix;

                        if(cin.fail()) {
                            cin.clear();
                            choix = -1;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        if(choix==1) {
                            cout << "Achat d'un livre" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Entrez le nom du livre" << endl;
                            getline(cin, titreLivre);

                            index = 0;
                            achatLivre = Livre();
                            while (index < nbLivres && achatLivre.getCode() == -1) {
                                if(titreLivre == livres[index].getTitre()) {
                                    achatLivre = livres[index];
                                }
                                index++;
                            }

                            if(achatLivre.getCode() != -1) {
                                bibliothèques[bibliothèqueCourant].acheterLivre(achatLivre);
                            }
                            else {
                                cout << "Erreur lors de l'achat du livre !" << endl;
                            }

                        }
                        else if(choix == 2) {
                            cout << "Suppression d'un livre de la bibliothèque" << endl;

                            cout << "Code du livre : " << endl;
                            cin >> choix;

                            bibliothèques[bibliothèqueCourant].supprimerLivre(choix);
                            choix = -1;
                        }
                        else if(choix == 3) {
                            cout << "Demande d'un livre à une autre bibliothèque " << endl;

                            cout << "Bibliothèque (code : entre : 0 et " << nbBibliothèques - 1
                            << ") :" << endl;
                            cin >> bibliothèqueDemande;

                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "ISBN du livre : "  << endl;
                            getline(cin, isbnLivreDemande);

                            if(bibliothèqueDemande > -1 && bibliothèqueDemande < nbLivres && bibliothèqueCourant != bibliothèqueDemande) {
                                bibliothèques[bibliothèqueCourant].demanderLivre(bibliothèques[bibliothèqueDemande], isbnLivreDemande) ;
                            }
                            else {
                                cout << "Erreur dans la demande d'un nouveau livre" << endl;
                            }



                        }
                        else if(choix == 4) {
                            cout << "Rendre un livre à sa bibliothèque d'origine" << endl;

                            cout << "Code de prêt du livre (code du livre) : " << endl;
                            cin >> choix;

                            bibliothèques[bibliothèqueCourant].terminerPrêt(bibliothèques, nbBibliothèques, choix);
                            choix = -1;
                        }
                        else if(choix == 5) {
                            bibliothèques[bibliothèqueCourant].afficherLivres();
                        }
                        else if(choix == 6) {
                            bibliothèques[bibliothèqueCourant].afficherPrêts();
                        }


                    }

                    choix = 3;
                }
                else if(choix == 2) {
                    cout << " Affichage des bibliothèques :" << endl;

                    for(int i=0; i < nbLivres; i++) {
                        bibliothèques[i].afficherBibliothèque();
                    }
                    pauseProgramme(2.);
                }

            }

            cout << "--> Retour au menu" << endl;
        }
        else if(choix==2) {
            cout << "Gestion des adhérents" << endl;
            choix = -1;

            while (choix != 3) {
                cout << "Vous pouvez effectuer un tas d'actions parmis celles proposée ci-dessous :" << endl;
                cout << " 1. Choisir un adhérent" << endl;
                cout << " 2. Afficher les adhérents" << endl;
                cout << " 3. Retour au menu" << endl;

                cin >> choix;

                if(cin.fail()) {
                    cin.clear();
                    choix = -1;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(choix==1) {
                    cout << "Choisissez un adhérent (code: nombre) : " << endl;
                    cin >> adhérentCourant;
                    choix = -1;
                    while(choix != 5 && adhérentCourant > -1 && adhérentCourant < nbAdhérents) {
                        cout << "(Adhérent " << adhérents[adhérentCourant]->getNom() << " " <<
                            adhérents[adhérentCourant]->getPrénom() << " " <<
                                adhérents[adhérentCourant]->getNombreEmpruntsRestants() << " emprunts restant" <<
                                ") Vous pouvez effectuer un tas d'actions parmis celles proposée ci-dessous :" << endl;

                        cout << " 1. Emprunter un livre" << endl;
                        cout << " 2. Rendre un livre" << endl;
                        cout << " 3. Afficher les emprunts" << endl;
                        cout << " 4. Afficher les livres de la bibliothèque" << endl;
                        cout << " 5. Retour au menu" << endl;

                        cin >> choix;

                        if(cin.fail()) {
                            cin.clear();
                            choix = -1;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        if(choix == 1){
                            cout << "Choisissez le code du livre à emprunté :" << endl;
                            cin >> choix;
                            try {
                                adhérents[adhérentCourant]->emprunterLivre(choix);
                            }
                            catch (SaisieInvalide e) {
                                cout << "Erreur lors de l'emprunt : " << e.what() << endl;
                            }


                            choix = 5;
                        }
                        else if(choix == 2) {
                            cout << "Choisissez le code du livre à rendre :" << endl;
                            cin >> choix;

                            adhérents[adhérentCourant]->rendreLivre(choix);

                            choix = 5;
                        }
                        else if(choix == 3) {
                            cout << "Affichage des emprunts de l'adhérent :" << endl;
                            adhérents[adhérentCourant]->afficherEmprunt();
                        }
                        else if(choix == 4) {
                            cout << "Affichage des livres de la bibliothèque de l'adhérent :" << endl;
                            adhérents[adhérentCourant]->getBibliothèque().afficherLivres();
                        }
                    }
                    choix = 3;
                }
                else if(choix==2) {
                    cout << " Affichage des adhérents :" << endl;

                    for(int i=0; i < nbAdhérents; i++) {
                        adhérents[i]->afficherAdhérent();
                    }
                    pauseProgramme(2.);
                }
            }

            cout << "--> Retour au menu" << endl;
        }
        else if(choix==3) {
            cout << "Ajout d'une bibliothèque : " << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nom :" << endl;
            getline(cin, nomBibliothèque);

            cout << "Adresse :" << endl;
            getline(cin, adresseBibliothèque);

            bibliothèques[nbBibliothèques] = Bibliothèque(nbBibliothèques, nomBibliothèque, adresseBibliothèque);
            nbBibliothèques++;

            cout << " La bibliothèque : " << nomBibliothèque << " a été correctement ajouté à la liste ! " << endl;

            pauseProgramme(1.);
            cout << "--> Retour au menu" << endl;
        }
        else if(choix==4) {
            cout << "Ajout d'un adhérent : " << endl;
            pauseProgramme(1.);

            cout << "Bibliothèque de rattachement (entre 0 et " << nbBibliothèques << ")" << endl;
            cin >> bibliothèqueAdhérent;

            cout << "Donc le nouvel adhérent sera rattaché à la bibliothèque : "
            << bibliothèques[bibliothèqueAdhérent].getNom() << " situé : " <<
                bibliothèques[bibliothèqueAdhérent].getAdresse() << endl;

            cout << "Validez-vous (Oui=1, Non=0) ?" << endl;
            cin >> choix;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            if(choix == 1) {
                cout << "Prénom Adhérent : " << endl;
                getline(cin, prénomAdhérent);

                cout << "Nom Adhérent : " << endl;
                getline(cin, nomAdhérent);

                cout << "Adresse Adhérent : " << endl;
                getline(cin, adresseAdhérent);

                cout << "Nombre d'emprunts maximale autorisée pour cet adhérent (nombre) : " << endl;
                cin >> nombreEmpruntsAdhérent;

                adhérents[nbAdhérents] = new Adhérent(bibliothèques[bibliothèqueAdhérent], nomAdhérent, prénomAdhérent,
                    adresseAdhérent, nbAdhérents, nombreEmpruntsAdhérent);
                nbAdhérents++;

                cout << "Le nouvel adhérent a été ajouté avec succès : " << endl;

            }

            cout << "--> Retour au menu" << endl;
        }
        else if(choix==5) {
            cout << "Affichage de tous les livres présent dans l'application :" << endl;
            for(int i=0; i < nbLivres; i++) {
                livres[i].afficherLivre();
            }
            pauseProgramme(5.);
            cout << "--> Retour au menu" << endl;
        }
        else if(choix==6) {

            cout << "Ouverture du créateur de livre :" << endl;
            choix = -1;
            while(choix != 6) {
                cout << "Quels types de livre voulez-vous créer ? :" << endl;
                pauseProgramme(0.3);

                cout << " 1. Roman" << endl;
                cout << " 2. Album" << endl;
                cout << " 3. Théâtre" << endl;
                cout << " 4. Poésie" << endl;
                cout << " 5. BD" << endl;
                cout << " 6. Éteindre l'application" << endl;

                cin >> choix;
                try {
                    if(choix > 0 && choix < 6) {
                    cout << "Création du livre :" << endl;
                    pauseProgramme(0.3);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "ISBN :" << endl;
                    getline(cin, isbnLivre);

                    cout << "Titre :" << endl;
                    getline(cin, nomLivre);

                    cout << "Auteur :" << endl;
                    getline(cin, nomAuteurLivre);

                    cout << "Éditeur :" << endl;
                    getline(cin, éditeurLivre);

                    cout << "Public cible :" << endl;
                    getline(cin, publicCibleLivre);

                    if(choix==1){
                        cout << "Genre :" << endl;
                        getline(cin, genreLivre);

                        livre = new Roman(isbnLivre, nbLivres, nomAuteurLivre, nomLivre, éditeurLivre,
                            publicCibleLivre, genreLivre);
                    }
                    else if(choix==2) {
                        cout << "Photos ? (0 ou 1) :" << endl;
                        cin >> photosLivre;

                        cout << "Dessins ? (0 ou 1) :" << endl;
                        cin >> dessinsLivre;

                        livre = new Album(isbnLivre, nbLivres, nomAuteurLivre, nomLivre, éditeurLivre,
                            publicCibleLivre, photosLivre, dessinsLivre);
                    }
                    else if(choix==3) {
                        cout << "Siècle (nombre) :" << endl;
                        cin >> siècleLivre;

                        livre = new Théâtre(isbnLivre, nbLivres, nomAuteurLivre, nomLivre, éditeurLivre,
                            publicCibleLivre, siècleLivre);
                    }
                    else if(choix==4) {
                        cout << "Prose ? (0 ou 1) :" << endl;
                        cin >> proseLivre;

                        cout << "Vers ? (0 ou 1) :" << endl;
                        cin >> versLivre;

                        livre = new Poésie(isbnLivre, nbLivres, nomAuteurLivre, nomLivre, éditeurLivre,
                            publicCibleLivre, versLivre, proseLivre);
                    }
                    else if(choix == 5) {
                        cout << "Dessinateur :" << endl;
                        getline(cin, dessinateurLivre);

                        livre = new BD(isbnLivre, nbLivres, nomAuteurLivre, nomLivre, éditeurLivre,
                            publicCibleLivre, dessinateurLivre);
                    }

                    livre->setCode(50 + nbLivres);
                    livres[nbLivres] = *livre;
                    nbLivres++;

                    cout << "Le livre a été ajouté avec succès !" << endl;
                    choix = 6;

                }
                }
                catch (SaisieInvalide e) {
                    cout << "Erreur lors de la cration du livre " << endl;
                    choix = 6;
                }


            }


            cout << "--> Retour au menu" << endl;
        }



    }


    cout << "/ --------------------------------------------------------- / " << endl;
    cout << " Merci d'avoir utilisé notre application, au revoir ! " << endl;


    return 0;
}