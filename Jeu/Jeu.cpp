

#include <iostream>
#include "Jeu.hpp"
#include "../Personnages/Amazone.hpp"
#include "../Personnages/Guerrier.hpp"
#include "../Personnages/Moine.hpp"
#include "../Personnages/Sorciere.hpp"

#include "../Objets/Armes.hpp"
#include "../Objets/Clef.hpp"
#include "../Objets/Potion.hpp"
#include "../Utilities/Utilities.cpp"

using namespace std;


vector<Objet *> initVecteurObjets() {

    vector<Objet *> ret;

    ///Potions
    //Potions de santé
    ret.push_back(new Potion("Potion de santé ordinaire", 5, 10, "sante"));
    ret.push_back(new Potion("Potion de santé extraordinaire", 10, 20, "sante"));
    ret.push_back(new Potion("Potion de santé légendaire", 30, 50, "sante"));

    //Potions d'habileté
    //TODO: a quoi sert l'habilete??
    ret.push_back(new Potion("Potion d'habileté  ordinaire", 1, 10, "habilete"));
    ret.push_back(new Potion("Potion d'habileté extraordinaire", 5, 20, "habilete"));
    ret.push_back(new Potion("Potion d'habileté  légendaire", 10, 50, "habilete"));

    //Potions de force Physique
    ret.push_back(new Potion("Potion de force physique ordinaire", 1, 10, "attaquePhysique"));
    ret.push_back(new Potion("Potion de force physique extraordinaire", 5, 20, "attaquePhysique"));
    ret.push_back(new Potion("Potion de force physique légendaire", 10, 50, "attaquePhysique"));


    //Potions de force Magique
    ret.push_back(new Potion("Potion de force magique ordinaire", 1, 10, "attaqueMagique"));
    ret.push_back(new Potion("Potion de force magique extraordinaire", 5, 20, "attaqueMagique"));
    ret.push_back(new Potion("Potion de force magique légendaire", 10, 50, "attaqueMagique"));


    //Potions de défense Physique
    ret.push_back(new Potion("Potion de résistance physique ordinaire", 1, 10, "resistancePhysique"));
    ret.push_back(new Potion("Potion de résistance physique extraordinaire", 5, 20, "resistancePhysique"));
    ret.push_back(new Potion("Potion de résistance physique légendaire", 10, 50, "resistancePhysique"));


    //Potions de défense Magique
    ret.push_back(new Potion("Potion de résistance magique ordinaire", 10, 1, "resistanceMagique"));
    ret.push_back(new Potion("Potion de résistance magique extraordinaire", 20, 5, "resistanceMagique"));
    ret.push_back(new Potion("Potion de résistance magique légendaire", 50, 10, "resistanceMagique"));

    //Poisons
    ret.push_back(new Potion("Poison ordinaire", 10, -5, "sante"));
    ret.push_back(new Potion("Poison extraordinaire", 20, -15, "sante"));
    ret.push_back(new Potion("Poison légendaire", 50, -30, "sante"));

    ///Armes et boucliers

    //Armes d'attaque magiques

    ret.push_back(new Armes("Baguette Magique ordinaire", 2, 0, 5, 0, 1));
    ret.push_back(new Armes("Baguette Magique extraordinaire", 10, 0, 10, 0, 3));
    ret.push_back(new Armes("Baguette Magique légendaire", 20, 0, 20, 0, 10));

    //Armes d'attaque physique
    ret.push_back(new Armes("Épée ordinaire", 2, 5, 0, 1, 0));
    ret.push_back(new Armes("Épée extraordinaire", 10, 10, 0, 3, 0));
    ret.push_back(new Armes("Épée légendaire", 20, 20, 0, 10, 0));

    //Armes de défense magiques
    ret.push_back(new Armes("Chevalière de sorcellerie ordinaire", 2, 0, 1, 0, 5));
    ret.push_back(new Armes("Chevalière de sorcellerie extraordinaire", 10, 0, 3, 0, 10));
    ret.push_back(new Armes("Chevalière de sorcellerie légendaire", 20, 0, 5, 0, 20));

    //Armes de défense physique
    ret.push_back(new Armes("Bouclier ordinaire", 2, 1, 0, 5, 0));
    ret.push_back(new Armes("Bouclier extraordinaire", 10, 3, 0, 10, 0));
    ret.push_back(new Armes("Bouclier légendaire", 20, 5, 0, 20, 0));

    //Armes attaque physique et magique
    ret.push_back(new Armes("Épée enchantée ordinaire", 5, 5, 5, 1, 1));
    ret.push_back(new Armes("Épée enchantée extraordinaire", 15, 10, 10, 3, 3));
    ret.push_back(new Armes("Excalibur", 30, 20, 20, 10, 10));

    //Armes defense physique et magique
    ret.push_back(new Armes("Pavois enchanté", 5, 1, 0, 5, 5));
    ret.push_back(new Armes("Bouclier en bois d'Yggdrasil", 15, 3, 3, 10, 10));
    ret.push_back(new Armes("Bouclier en acier Valyrien", 30, 5, 5, 20, 20));

    //Armes melangée
    ret.push_back(new Armes("Épée défensive ordinaire", 5, 5, 0, 5, 2));
    ret.push_back(new Armes("Épée défensive extraordinaire", 15, 10, 0, 10, 5));
    ret.push_back(new Armes("Épée défensive légendaire", 30, 20, 0, 20, 10));

    //Armes ultimes
    ret.push_back(new Armes("Épée ultime", 50, 40, 20, 4, 4));
    ret.push_back(new Armes("Bouclier ultime", 50, 0, 40, 0, 40));


    //TODO: clef de teleportation

    return ret;
}


vector<Objet *> Jeu::objetsPossibles{initVecteurObjets()};


//TODO: make it check that value of joueurs> joueurNonAuto
Jeu::Jeu(int joueurNonAuto, int joueurs, unsigned int chateauLength, unsigned int chateauWidth)
        : nombreJoueurNonAutomatise(joueurNonAuto),
          nombreDeJoueurs(joueurs) {
    chateau = new Chateau(chateauWidth, chateauLength);
    objectFactory = new ObjectFactory(objetsPossibles);
    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge
    initVecteurPersonnages();


}

Jeu::Jeu() : nombreJoueurNonAutomatise(1), nombreDeJoueurs(5) {
    chateau = new Chateau(4, 4);
    objectFactory = new ObjectFactory(objetsPossibles);
    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge

    initVecteurPersonnages();

}

void Jeu::initJoueurs() {
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
            choice = utilities::validateRange(choice, 1, personnagesDisponiblesEtFrequences.size());
            cout << "Bon choix. \n Vous êtes digne d'un prénom également. Quel est votre prénom?" << endl;
            cin >> name;

        }
        cout << "Le joueur " << name << " a choisi un(e) "
             << personnagesDisponiblesEtFrequences[choice - 1].first->getName() << endl;

        joueurs.push_back(new Joueur(name, forge(choice - 1), (i + 1 > nombreJoueurNonAutomatise)));

    }

}


Jeu::~Jeu() {
    for (long int i = 0; i < personnagesDisponiblesEtFrequences.size(); i++) {
        delete personnagesDisponiblesEtFrequences[i].first;
    }

    for (long int i = 0; i < joueurs.size(); i++) {
        delete joueurs[i];
    }
}

Personnage *Jeu::forge(int choice) {
    personnagesDisponiblesEtFrequences[choice].second += 1;
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

unsigned int Jeu::choosePersonnageAutom() {
    int min = personnagesDisponiblesEtFrequences[0].second;
    unsigned int choice = 1;
    for (unsigned int i = 1; i < personnagesDisponiblesEtFrequences.size(); i++) {
        if (min > personnagesDisponiblesEtFrequences[i].second) {
            min = personnagesDisponiblesEtFrequences[i].second;
            choice = i + 1;
        }
    }
    return choice;
}


void Jeu::lancePartie() {
    initJoueurs();
    placeJoueurs();
    placeObjets();
}


void Jeu::placeJoueurs() {
    int x, y;

    //Vrais joueurs sont placés de manière random
    for (unsigned int i = 0; i < nombreJoueurNonAutomatise; i++) {
        //TODO: careful, might be source of slow execution
        do {
            x = utilities::random(0, chateau->getWidth() - 1);
            y = utilities::random(0, chateau->getLength() - 1);

            if (chateau->map[x][y]->numOfPlayers() == 0) {

                joueurs[i]->setPosition(x, y);
                chateau->map[x][y]->addPlayer(joueurs[i]);
                cout << "Joueur " << joueurs[i]->getName() << " est placé dans la salle " << chateau->map[x][y]->getId()
                     << "." << endl;
            }
        } while (!joueurs[i]->isPlaced());
    }

    for (unsigned int i = nombreJoueurNonAutomatise; i < joueurs.size(); i++) {
        pair<int, int> minCoords = chateau->getEmptiestRoom();
        joueurs[i]->setPosition(minCoords.first, minCoords.second);
        chateau->map[minCoords.first][minCoords.second]->addPlayer(joueurs[i]);
        // cout<<"Joueur "<<joueurs[i]->getName()<<" est placé dans la salle "<<chateau->map[minCoords.first][minCoords.second]->getId()<<"."<<endl;

    }

    for (int i = 0; i < chateau->getWidth(); i++) {
        for (int j = 0; j < chateau->getLength(); j++) {
            if (chateau->map[i][j]->numOfPlayers() > 0)
                cout << "Salle " << chateau->map[i][j]->getId() << " has " << chateau->map[i][j]->numOfPlayers()
                     << " players." << endl;
        }
    }

}

void Jeu::initVecteurPersonnages() {
    pair<Personnage *, int> pair1(new Amazone(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair1);

    pair<Personnage *, int> pair2(new Guerrier(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair2);

    pair<Personnage *, int> pair3(new Moine(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair3);

    pair<Personnage *, int> pair4(new Sorciere(), 0);
    personnagesDisponiblesEtFrequences.push_back(pair4);

}

void Jeu::moveJoueur(Joueur *joueur, int x, int y) {
    pair<int, int> currPosition = joueur->getPosition();

    chateau->map[currPosition.first][currPosition.second]->removePlayer(joueur);

    joueur->setPosition(x, y);
    chateau->map[x][y]->addPlayer(joueur);

}

void Jeu::placeObjets() {
    for (long unsigned int i = 0; i < chateau->width; i++) {
        for (long unsigned int j = 0; j < chateau->length; j++) {
            Objet *objet1 = objectFactory->produce();
            Objet *objet2 = objectFactory->produce();
            chateau->map[i][j]->placeObject(objet1);
            chateau->map[i][j]->placeObject(objet2);
        }
    }
}
