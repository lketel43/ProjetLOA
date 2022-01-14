

#include <iostream>
#include "Jeu.hpp"
#include "../Personnages/Amazone.hpp"
#include "../Personnages/Guerrier.hpp"
#include "../Personnages/Moine.hpp"
#include "../Personnages/Sorciere.hpp"

#include "../Objets/Arme.hpp"
#include "../Objets/Clef.hpp"
#include "../Objets/Potion.hpp"
#include "../Utilities/Utilities.cpp"
#include "JoueurAutomatique.hpp"
#include "JoueurManuel.hpp"

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

    ///Arme et boucliers

    //Arme d'attaque magiques

    ret.push_back(new Arme("Baguette Magique ordinaire", 2, 0, 5, 0, 1));
    ret.push_back(new Arme("Baguette Magique extraordinaire", 10, 0, 10, 0, 3));
    ret.push_back(new Arme("Baguette Magique légendaire", 20, 0, 20, 0, 10));

    //Arme d'attaque physique
    ret.push_back(new Arme("Épée ordinaire", 2, 5, 0, 1, 0));
    ret.push_back(new Arme("Épée extraordinaire", 10, 10, 0, 3, 0));
    ret.push_back(new Arme("Épée légendaire", 20, 20, 0, 10, 0));

    //Arme de défense magiques
    ret.push_back(new Arme("Chevalière de sorcellerie ordinaire", 2, 0, 1, 0, 5));
    ret.push_back(new Arme("Chevalière de sorcellerie extraordinaire", 10, 0, 3, 0, 10));
    ret.push_back(new Arme("Chevalière de sorcellerie légendaire", 20, 0, 5, 0, 20));

    //Arme de défense physique
    ret.push_back(new Arme("Bouclier ordinaire", 2, 1, 0, 5, 0));
    ret.push_back(new Arme("Bouclier extraordinaire", 10, 3, 0, 10, 0));
    ret.push_back(new Arme("Bouclier légendaire", 20, 5, 0, 20, 0));

    //Arme attaque physique et magique
    ret.push_back(new Arme("Épée enchantée ordinaire", 5, 5, 5, 1, 1));
    ret.push_back(new Arme("Épée enchantée extraordinaire", 15, 10, 10, 3, 3));
    ret.push_back(new Arme("Excalibur", 30, 20, 20, 10, 10));

    //Arme defense physique et magique
    ret.push_back(new Arme("Pavois enchanté", 5, 1, 0, 5, 5));
    ret.push_back(new Arme("Bouclier en bois d'Yggdrasil", 15, 3, 3, 10, 10));
    ret.push_back(new Arme("Bouclier en acier Valyrien", 30, 5, 5, 20, 20));

    //Arme melangée
    ret.push_back(new Arme("Épée défensive ordinaire", 5, 5, 0, 5, 2));
    ret.push_back(new Arme("Épée défensive extraordinaire", 15, 10, 0, 10, 5));
    ret.push_back(new Arme("Épée défensive légendaire", 30, 20, 0, 20, 10));

    //Arme ultimes
    ret.push_back(new Arme("Épée ultime", 50, 40, 20, 4, 4));
    ret.push_back(new Arme("Bouclier ultime", 50, 0, 40, 0, 40));


    //TODO: clef de teleportation

    return ret;
}

Potion *Potion::copy() {
    return new Potion(nom, rarete, boost, type);
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
    utilities::display("Introductory text: needs completion \n");

    //TODO: need to figure out name situation
    utilities::display("Il est temps pour chaque joueur de choisir son personnage.\n");
    utilities::display("Voici les personnages possibles, et leur stats.\n");

    for (long unsigned int i = 0; i < personnagesDisponiblesEtFrequences.size(); i++) {
        utilities::display("Personnage " + to_string(i + 1) + ": \n"
                           + "Nom: " + personnagesDisponiblesEtFrequences[i].first->getName() + "\n" +
                           personnagesDisponiblesEtFrequences[i].first->getStats() + "\n");

    }

    utilities::display("Maintenant que vous connaissez les personnages, à vous de choisir lequel sera le vôtre.\n");

    for (int i = 0; i < nombreDeJoueurs; i++) {

        //Si on a déjà demandé a tous les joueurs et il reste que les automatisés
        if (i + 1 > nombreJoueurNonAutomatise) {
            choice = choosePersonnageAutom();
            name = std::to_string(i + 1);

        } else {
            utilities::display("À vous Joueur " + to_string(i + 1) + " de choisir votre personnage." + "\n" +
                               "Choisissez un nombre entre 1 et " +
                               to_string(personnagesDisponiblesEtFrequences.size()) + "." + "\n"
                               + "Attention! Ce choix est définitif." + "\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, personnagesDisponiblesEtFrequences.size());
            utilities::display("Bon choix. \n");
            utilities::display("Vous êtes digne d'un prénom également. Quel est votre prénom?\n");
            cin >> name;

        }
        utilities::display("Le joueur " + name + " a choisi un(e) "
                           + personnagesDisponiblesEtFrequences[choice - 1].first->getName() + "\n");

        if (i + 1 > nombreJoueurNonAutomatise) {
            joueurs.push_back(new JoueurAutomatique(name, forge(choice - 1)));
        }
        else{
            joueurs.push_back(new JoueurManuel(name, forge(choice-1)));
        }
    }

}


Jeu::~Jeu() {
//    for (long int i = 0; i < personnagesDisponiblesEtFrequences.size(); i++) {
//        delete personnagesDisponiblesEtFrequences[i].first;
//    }

    for (long int i = 0; i < joueurs.size(); i++) {
        if (joueurs[i] != nullptr)
            delete joueurs[i];
    }

//    for(long unsigned int i = 0; i< objetsPossibles.size(); i++)
//        delete objetsPossibles[i];

    delete chateau;
    delete objectFactory;
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

    for (int i = 0; i < joueurs.size(); i++) {
        tour(joueurs[i]);
    }
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
                utilities::display("Joueur " + joueurs[i]->getName() + " est placé dans la salle " +
                                   to_string(chateau->map[x][y]->getId())
                                   + ".\n");

            }
        } while (!joueurs[i]->isPlaced());
    }

    for (unsigned int i = nombreJoueurNonAutomatise; i < joueurs.size(); i++) {
        pair<int, int> minCoords = chateau->getEmptiestRoom();
        joueurs[i]->setPosition(minCoords.first, minCoords.second);
        chateau->map[minCoords.first][minCoords.second]->addPlayer(joueurs[i]);

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

void Jeu::tour(Joueur *joueur) {
    pair<int, int> position = joueur->getPosition();
    Salle *salle = chateau->map[position.first][position.second];

    if (!joueur->isAutomatise()) {
        if (nombreJoueurNonAutomatise > 1) {
            utilities::display("Tour du Joueur " + joueur->getName() + "\n");
        }
        salle->display();
        //TODO: make joueur display its stats
        int choice;
        do {
            utilities::display("Que voulez-vous faire?\n");
            utilities::display("1. Consulter/modifier votre sac et votre équipement.\n");
            utilities::display("2. Ramasser des objets.\n");
            utilities::display("3. Commencer un combat. \n");
            utilities::display("4. Finir votre tour. \n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 4);
            //TODO: take into consideration that some options might not be viable (ex. can't battle if nobody's there, etc.)
            switch (choice) {
                case 1:
                    checkBag(joueur);
                    break;
                case 2:
//                    pickUpObjects(joueur);
                    break;
                case 3:
//                    startBattle(joueur);
                    break;
                case 4:
                    endTurn(joueur);
                    break;
                default:
                    utilities::display("Error! choice of action is not a valid one.");
            }

        } while (choice != 4);

    }


}


//TODO: NOT DONE!!!!!
void Jeu::checkBag(Joueur *joueur) {
    //TODO: add things to organize bag



}

void Jeu::endTurn(Joueur *joueur) {
    pair<int, int> position = joueur->getPosition();
    Salle *salle = chateau->map[position.first][position.second];
    int choice;
    string directions = "";
    utilities::display("Vous avez decidé de finir votre tour.\n");
    utilities::display("Avant de faire ceci, voulez-vous changer de salle?\n");
    utilities::display("1. Oui \n2. Non\n");

    cin >> choice;
    choice = utilities::validateRange(choice, 1, 2);
    if (choice == 1) {
        utilities::display("Vous avez choisi de changer de salle avant la fin de votre tour.\n");
        utilities::display("Voici la carte du chateau, votre position est marquée par un 'x'\n");
        chateau->display(joueur->getPosition());

        if (salle->nord() != nullptr)
            directions += to_string(salle->nord()->getId()) + ",";
        if (salle->sud() != nullptr)
            directions += " " + to_string(salle->sud()->getId()) + ",";
        if (salle->est() != nullptr)
            directions += " " + to_string(salle->est()->getId()) + ",";
        if (salle->ouest() != nullptr)
            directions += " " + to_string(salle->ouest()->getId()) + ",";

        directions[directions.length() - 1] = '.';

        utilities::display("Vous avez donc le choix d'aller dans les salles suivantes: " + directions + "\n");

// TODO; FINISH
    }
    utilities::display("Fin de tour pour le Joueur " + joueur->getName() + "\n");
}

void Jeu::displayMap(Joueur * joueur) const{
    chateau->display(joueur->getPosition());

}

unsigned int Jeu::getNumberOfSalles() const {
    return chateau->width * chateau->length;
}

pair<int, int>  Jeu::getSallePosition(int & num) const {
    return chateau->getSalleCoordinates(num);
}