

#include <iostream>
#include "Jeu.hpp"
#include "../Personnages/Amazone.hpp"
#include "../Personnages/Guerrier.hpp"
#include "../Personnages/Moine.hpp"
#include "../Personnages/Sorciere.hpp"

using namespace std;

//TODO: make it check that value of joueurs> joueurNonAuto
Jeu::Jeu(int joueurNonAuto, int joueurs, unsigned int chateauLength, unsigned int chateauWidth)
        : nombreJoueurNonAutomatise(joueurNonAuto),
          nombreDeJoueurs(joueurs) {
    chateau = new Chateau(chateauWidth, chateauLength);
    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge
    personnagesDisponibles.push_back(new Amazone());
    personnagesDisponibles.push_back(new Guerrier());
    personnagesDisponibles.push_back(new Moine());
    personnagesDisponibles.push_back(new Sorciere());

}

Jeu::Jeu() : nombreJoueurNonAutomatise(1), nombreDeJoueurs(5) {
    chateau = new Chateau(5, 5);

}

void Jeu::setPlayers() {
    int choice;
    string name;
    //TODO: ecrire text du début
    cout << "Introductory text: needs completion" << endl;

    //TODO: need to figure out name situation

    cout << "Il est temps pour chaque joueur de choisir son personnage" << endl
         << "Voici les personnages possibles, et leur stats." << endl;

    for (long unsigned int i = 0; i < personnagesDisponibles.size(); i++) {
        cout << "Personnage " << i + 1 << ": " << endl;
        cout << "Nom: " << personnagesDisponibles[i]->getName() << endl;
        cout << personnagesDisponibles[i]->getStats() << endl;
        cout << endl;
    }

    cout << "Maintenant que vous connaissez les personnages, à vous de choisir lequel sera le vôtre." << endl;
    if (nombreJoueurNonAutomatise > 1) {
        for (int i = 0; i < nombreDeJoueurs; i++) {
            cout << "À vous Joueur " << i + 1 << " de choisir votre personnage." << endl
                 << "Choisissez un nombre entre 1 et " << personnagesDisponibles.size() << "." << endl
                 << "Attention! Ce choix est définitif." << endl;
            //Si on a déjà demandé a tous les joueurs et il reste que les automatisés
            if (i + 1 > nombreJoueurNonAutomatise) {
                choice = choosePersonnageAutom();
                name = std::to_string(i + 1);

            } else {
                cin >> choice;
                //TODO: need to validate choice is in good range
                cout<<" Vous êtes digne d'un prénom également. Quel est votre prénom?"<<endl;
                cin>>name;
            }
            cout << "Le joueur " << name << " a choisi un "<< personnagesDisponibles[choice - 1]->getName()<<endl;
            joueurs.push_back(new Joueur(name, forge(choice - 1),(i + 1 > nombreJoueurNonAutomatise)));

        }
    }


}

Personnage *Jeu::forge(int choice) {
    string type = personnagesDisponibles[choice]->getName();
    //switching on first letter of the type chosen
    switch (type[0]) {
        case 'a':
            return new Amazone();
        case 'g':
            return new Guerrier();
        case 'm':
            return new Moine();
        case 's':
            return new Sorciere();
        default:
            cout<<"Erreur réalisée en cours de forgement d'un personnage de type  "<<type<<endl;
            return nullptr;

    }
}
