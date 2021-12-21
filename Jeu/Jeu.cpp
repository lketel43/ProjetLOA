

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
    pair<Personnage *, int> pair1(new Amazone(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair1);

    pair<Personnage *, int> pair2(new Guerrier(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair2);

    pair<Personnage *, int> pair3(new Moine(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair3);

    pair<Personnage *, int> pair4(new Sorciere(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair4);


}

Jeu::Jeu() : nombreJoueurNonAutomatise(1), nombreDeJoueurs(5) {
    chateau = new Chateau(5, 5);
    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge

    pair<Personnage *, int> pair1(new Amazone(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair1);

    pair<Personnage *, int> pair2(new Guerrier(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair2);

    pair<Personnage *, int> pair3(new Moine(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair3);

    pair<Personnage *, int> pair4(new Sorciere(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair4);

}

void Jeu::setPlayers() {
    int choice;
    string name;
    //TODO: ecrire text du début
    cout << "Introductory text: needs completion" << endl;

    //TODO: need to figure out name situation

    cout << "Il est temps pour chaque joueur de choisir son personnage." << endl
         << "Voici les personnages possibles, et leur stats." << endl;

    for (long unsigned int i = 0; i < personnagesDisponiblesEtFrequences.size(); i++) {
        cout << "Personnage " << i + 1 << ": " << endl;
        cout << "Nom: " << personnagesDisponiblesEtFrequences[i].first->getName() << endl;
        cout << personnagesDisponiblesEtFrequences[i].first->getStats() << endl;
    }

    cout << "Maintenant que vous connaissez les personnages, à vous de choisir lequel sera le vôtre." << endl;

    for (int i = 0; i < nombreDeJoueurs; i++) {

        //Si on a déjà demandé a tous les joueurs et il reste que les automatisés
        if (i + 1 > nombreJoueurNonAutomatise) {
            choice = choosePersonnageAutom();
            name = std::to_string(i + 1);

        } else {
            cout << "À vous Joueur " << i + 1 << " de choisir votre personnage." << endl
                 << "Choisissez un nombre entre 1 et " << personnagesDisponiblesEtFrequences.size() << "." << endl
                 << "Attention! Ce choix est définitif." << endl;
            cin >> choice;
            //TODO: need to validate choice is in good range
            cout << " Vous êtes digne d'un prénom également. Quel est votre prénom?" << endl;
            cin >> name;
        }
        cout << "Le joueur " << name << " a choisi un(e) "
             << personnagesDisponiblesEtFrequences[choice - 1].first->getName() << endl;

        joueurs.push_back(new Joueur(name, forge(choice - 1), (i + 1 > nombreJoueurNonAutomatise)));

    }


}

Personnage *Jeu::forge(int choice) {
    string type = personnagesDisponiblesEtFrequences[choice].first->getName();
    //switching on first letter of the type chosen
    switch (type[0]) {
        case 'a':
        case 'A':
            return new Amazone();
        case 'g':
        case 'G':
            return new Guerrier();
        case 'm':
        case 'M':
            return new Moine();
        case 's':
        case 'S':
            return new Sorciere();
        default:
            cout << "Erreur réalisée en cours de forgement d'un personnage de type  " << type << endl;
            return nullptr;

    }
}

int Jeu::choosePersonnageAutom() {
    int min = personnagesDisponiblesEtFrequences[0].second;
    unsigned int choice = 1;
    for (unsigned int i = 1; i < personnagesDisponiblesEtFrequences.size(); i++) {
        if (min > personnagesDisponiblesEtFrequences[i].second) {
            min = personnagesDisponiblesEtFrequences[i].second;
            choice = i + 1;
        }
    }

    personnagesDisponiblesEtFrequences[choice - 1].second +=1;
    return choice;
}

void Jeu::lancePartie() {
    setPlayers();
}