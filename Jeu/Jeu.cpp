

#include <iostream>
#include "Jeu.hpp"
#include "../Personnages/Amazone.hpp"
#include "../Personnages/Guerrier.hpp"
#include "../Personnages/Moine.hpp"
#include "../Personnages/Sorciere.hpp"

#include "../Objets/Arme.hpp"
#include "../Objets/Clef.hpp"
#include "../Objets/Potion.hpp"
#include "../Utilities/utilities.hpp"
#include "JoueurAutomatique.hpp"
#include "JoueurManuel.hpp"
#include "Combat.hpp"

using namespace std;


vector<Objet *> initVecteurObjets() {

    vector<Objet *> ret;

    ///Potions
    //Potions de santé
    ret.push_back(new Potion("Potion de santé ordinaire", 5, 10, "sante"));
    ret.push_back(new Potion("Potion de santé extraordinaire", 10, 20, "sante"));
    ret.push_back(new Potion("Potion de santé légendaire", 30, 50, "sante"));

    //Potions d'habileté
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

    ret.push_back(new Clef("Clef de téléportation", 10,
                           "Cette clef vous permet de changer de salle sans finir votre tour.\nAttention, elle est à utilisation unique.\n "));

    return ret;
}


void Jeu::initVecteursJoueurs() {
    for (unsigned int i = 0; i < nombreJoueurNonAutomatise; i++) {
        joueurs.push_back(new JoueurManuel(to_string(i + 1)));
    }
    for (unsigned int i = nombreJoueurNonAutomatise; i < nombreDeJoueurs; i++) {
        joueurs.push_back(new JoueurAutomatique(to_string(i + 1)));
    }
}


Jeu::Jeu(int joueurNonAuto, int joueurs, unsigned int chateauLength, unsigned int chateauWidth)
        : nombreDeJoueurs(joueurs), nombreJoueurNonAutomatise(joueurNonAuto) {
    if (joueurNonAuto >= joueurs) throw std::invalid_argument("joueurNon is not suppose to be higher than joueurs");
    chateau = new Chateau(chateauWidth, chateauLength);

    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge
    initVecteurPersonnages();
    initVecteursJoueurs();
    objetsPossibles = initVecteurObjets();
}

Jeu::Jeu() : nombreDeJoueurs(16), nombreJoueurNonAutomatise(1) {
    chateau = new Chateau(4, 4);
    delete objectFactory;
    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge
    initVecteurPersonnages();
    initVecteursJoueurs();
    objetsPossibles = initVecteurObjets();

}

vector<Joueur *> Jeu::getJoueurs() const {
    return joueurs;
}

void Jeu::removeJoueur(Personnage *mort) {
    for (unsigned int i = 0; i < joueurs.size(); i++) {
        if (&(*joueurs[i]->getPersonnage()) == &(*mort)) {
            joueurs.erase(joueurs.begin() + i);
            break;
        }
    }
}

void Jeu::initJoueurs() {
    int choice;

    utilities::display("Il est temps pour chaque joueur de choisir son personnage.\n");
    utilities::display("Voici les personnages possibles, et leur stats.\n");

    for (long unsigned int i = 0; i < personnagesDisponiblesEtFrequences.size(); i++) {
        utilities::display("Personnage " + to_string(i + 1) + ": \n"
                           + "Nom: " + personnagesDisponiblesEtFrequences[i].first->getName() + "\n" +
                           personnagesDisponiblesEtFrequences[i].first->getStats() + "\n");
    }

    utilities::display("Maintenant que vous connaissez les personnages, à vous de choisir lequel sera le vôtre.\n");

    for (long unsigned int i = 0; i < joueurs.size(); i++) {
        choice = joueurs[i]->choosePersonnage(personnagesDisponiblesEtFrequences);

        if (!joueurs[i]->isAutomatise())
            utilities::display("Le joueur " + joueurs[i]->getName() + " a choisi un(e) "
                               + personnagesDisponiblesEtFrequences[choice - 1].first->getName() + "\n");

        joueurs[i]->setPersonnage(forge(choice - 1));
        //if (!joueurs[i]->isAutomatise()) joueurs[i]->ramasser(objectFactory->producePoison()); TEST Potion poison
        //Equipage des joueurs automatisés avec des armes basiques et une potion
        if (joueurs[i]->isAutomatise()) {
            joueurs[i]->equiper(objectFactory->produceArmeBasique());
            joueurs[i]->equiper(objectFactory->produceArmeBasique());
            joueurs[i]->ramasser(objectFactory->producePotion());
        }
    }

}


Jeu::~Jeu() {
//    for (long int i = 0; i < personnagesDisponiblesEtFrequences.size(); i++) {
//        delete personnagesDisponiblesEtFrequences[i].first;
//    }

    for (unsigned int i = 0; i < joueurs.size(); i++) {
        if (joueurs[i] != nullptr) {
            delete joueurs[i];
        }

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


bool Jeu::lancePartie() {
    unsigned int choice;
    objectFactory = new ObjectFactory(objetsPossibles);
    initJoueurs();
    placeJoueurs();
    placeObjets();


    while (!this->partieFinie) {
        renforcerJoueursAutomatises();
        spotLast();
        for (unsigned int i = 0; i < joueurs.size(); i++) {
            tour(joueurs[i]);
        }
    }

    utilities::display("Voulez-vous relancer une autre partie?\n");
    utilities::display("1.Oui\n2.Non\n");
    choice = utilities::validateRange(1, 2);
    return (choice == 1);


}

void Jeu::renforcerJoueursAutomatises() {
    int random;
    int count;
    Personnage *personnage;
    vector<Objet *> equipement;

    if (joueurs.size() < nombreDeJoueurs / 2) {
        if (joueurs.size() < nombreDeJoueurs / 4) {
            if (joueurs.size() == 2) {
                //trouver l'autre joueur et le transformer en big boss
                utilities::display("Il vous reste un ennemi final. Mais attention: il est légendaire!\n");
                for (long unsigned int i = 0; i < joueurs.size(); i++) {
                    if (joueurs[i]->isAutomatise()) {
                        personnage = joueurs[i]->getPersonnage();
                        equipement = personnage->getEquipement();
                        //TODO might be source of error
                        while (!equipement.empty()) {
                            delete equipement[0];
                            personnage->removeFromEquipement(0);
                        }
                        joueurs[i]->equiper(objectFactory->produireArmeLegendaire());
                        joueurs[i]->equiper(objectFactory->produireBouclierLegendaire());

                    }
                }
            } else {
                //donner a tous les joueurs des armes automatiques fortes
                utilities::display("Vos ennemis deviennent plus forts!\n");
                for (long unsigned int i = 0; i < joueurs.size(); i++) {
                    //chercher tous les joueurs AUTOMATIQUES
                    if (joueurs[i]->isAutomatise()) {
                        personnage = joueurs[i]->getPersonnage();
                        equipement = personnage->getEquipement();
                        //TODO might be source of error
                        //delete leur equipement
                        while (!equipement.empty()) {
                            delete equipement[0];
                            personnage->removeFromEquipement(0);
                        }
                        //leur donner deux armes fortes
                        joueurs[i]->equiper(objectFactory->produceArmeExtraordinaire());
                        joueurs[i]->equiper(objectFactory->produceArmeExtraordinaire());
                    }

                }
            }
        } else {
            //choisir deux joueurs et leur donner deux potions(au plus)
            count = 1;
            for (long unsigned int i = 0; i < joueurs.size(); i++) {
                random = utilities::random(0, joueurs.size() - 1);
                if (joueurs[random]->isAutomatise()) {
                    if (!joueurs[random]->getPersonnage()->isSacFull()) {
                        count++;
                        joueurs[random]->ramasser(objectFactory->producePotion());
                        if (!joueurs[random]->getPersonnage()->isSacFull()) {
                            joueurs[random]->ramasser(objectFactory->producePotion());
                        }
                        if (count > 2)
                            return;
                        i = 0;
                    }
                }
            }
        }

    } else {
        //choisir joueur random et lui donner une potion
        for (long unsigned int i = 0; i < joueurs.size(); i++) {
            random = utilities::random(0, joueurs.size() - 1);
            if (joueurs[random]->isAutomatise()) {
                if (!joueurs[random]->getPersonnage()->isSacFull()) {
                    joueurs[random]->ramasser(objectFactory->producePotion());
                    return;
                }
            }
        }
    }
}


void Jeu::placeJoueurs() {
    int x, y;

    //Vrais joueurs sont placés de manière random
    for (unsigned int i = 0; i < nombreJoueurNonAutomatise; i++) {
        do {
            x = utilities::random(0, chateau->getWidth() - 1);
            y = utilities::random(0, chateau->getLength() - 1);

            if (chateau->map[x][y]->numOfPlayers() == 0) {

                joueurs[i]->getPersonnage()->setPosition(x, y);
                chateau->map[x][y]->addPlayer(joueurs[i]);
                utilities::display("Joueur " + joueurs[i]->getName() + " est placé dans la salle " +
                                   to_string(chateau->map[x][y]->getId())
                                   + ".\n");

            }
        } while (!joueurs[i]->getPersonnage()->isPlaced());
    }

    for (unsigned int i = nombreJoueurNonAutomatise; i < joueurs.size(); i++) {
        pair<int, int> minCoords = chateau->getEmptiestRoom();
        joueurs[i]->getPersonnage()->setPosition(minCoords.first, minCoords.second);
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
    pair<int, int> currPosition = joueur->getPersonnage()->getPosition();

    chateau->map[currPosition.first][currPosition.second]->removePlayer(joueur);

    joueur->getPersonnage()->setPosition(x, y);
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
    pair<int, int> position = joueur->getPersonnage()->getPosition();
    Salle *salle = chateau->map[position.first][position.second];

    if (!joueur->isAutomatise()) {
        if (nombreJoueurNonAutomatise > 1) {
            utilities::display("Tour du Joueur " + joueur->getName() + "\n");
        }
        salle->display();
        int choice;
        do {
            utilities::display("Que voulez-vous faire?\n");
            utilities::display("1. Consulter/modifier votre sac et votre équipement.\n");
            utilities::display("2. Ramasser des objets.\n");
            utilities::display("3. Commencer un combat. \n");
            utilities::display("4. Finir votre tour. \n");

            choice = utilities::validateRange(1, 4);
            switch (choice) {
                case 1:
                    joueur->consulterSacEtEquipement(this);
                    break;
                case 2:
                    joueur->pickUpObjects(this);
                    break;
                case 3: {
                    if (salle->hasNoOtherPlayers()) {
                        utilities::display("Il n'y a pas d'ennemi ici.\n");
                        break;
                    }
                    // Afficher les perso de la salle
                    utilities::display("Pour rappel, voici vos statistiques: \n");
                    utilities::display(joueur->getPersonnage()->getStats());
                    vector<pair<Joueur *, int> > ennemies{salle->displayEnnemi(joueur)};
                    utilities::display("Choisissez un ennemi à combattre:\n");
                    // Faire le le choix
                    int choiceEnnemi;
                    choiceEnnemi = utilities::validateRange(1, salle->nbEnnemi());
                    // Créer le combat et le lancer
                    int index = ennemies[choiceEnnemi - 1].second;
                    if (joueur->getPersonnage()->getHabilete() >=
                        salle->getJoueur()[index]->getPersonnage()->getHabilete()) {
                        Combat c{joueur, salle->getJoueur()[index]};
                        c.commencerCombat();
                    } else {
                        Combat c{salle->getJoueur()[index], joueur};
                        c.commencerCombat();
                    }

                    //Mort éventuelle des joueurs
                    Joueur *m2 = salle->getJoueur()[index]->mort(this);
                    if (m2 != nullptr) {
                        utilities::display("L'ennemi " + m2->getPersonnage()->getName() +
                                           " fait tomber au sol les objets suivants:\n");
                        for (unsigned int i = 0; i < m2->getPersonnage()->getSac().size(); i++) {
                            salle->placeObject(m2->getPersonnage()->getSac()[i]);
                            utilities::display(m2->getPersonnage()->getSac()[i]->getNom() + "\n");
                        }

                        for (unsigned int i = 0; i < m2->getPersonnage()->getEquipement().size(); i++) {
                            utilities::display(m2->getPersonnage()->getEquipement()[i]->getNom() + "\n");
                            salle->placeObject(m2->getPersonnage()->getEquipement()[i]);
                        }
                        utilities::display(
                                "Vous retrouverez également une potion de santé dans la salle pour vous récompenser.\n");
                        delete m2;
                    }

                    //Si tous les ennemis ont été vaincus
                    if (this->joueurs.size() == 1) {
                        utilities::display("Tous les ennemis ont été vaincus, la partie se termine.\n");
                        this->partieFinie = true;
                        return;
                    }

                    //Mort joueurManuel
                    Joueur *m1 = joueur->mort(this);
                    if (m1 != nullptr) {
                        utilities::display("Vous avez été vaincu, la partie se termine.\n");
                        this->partieFinie = true;
                        return;
                    }

                    salle->placeObject(objectFactory->producePotionDeSanteExtra());
                    break;
                }
                case 4:
                    if (salle->hasNoOtherPlayers()) {
                        //changer objets dans la salle qu'il va quitter
                        while (!salle->hasNoObjects()) {
                            salle->removeObject(0);
                        }

                        salle->placeObject(objectFactory->produce());
                        salle->placeObject(objectFactory->produce());
                        joueur->endTurn(this);

                    } else {
                        utilities::display(
                                "Il vous reste encore des ennemis à combattre ici.\nVous ne pouvez pas finir votre tour maintenant.\n");
                    }
                    break;
                default:
                    utilities::display("Error! choice of action is not a valid one.");
            }

        } while (choice != 4);

    } else {
        joueur->endTurn(this);
    }

}


void Jeu::displayMap(Joueur *joueur) const {
    chateau->display(joueur->getPersonnage()->getPosition());

}

unsigned int Jeu::getNumberOfSalles() const {
    return chateau->width * chateau->length;
}

pair<int, int> Jeu::getSallePosition(int num) const {
    return chateau->getSalleCoordinates(num);

}

void Jeu::placerDansSalle(std::pair<int, int> position, Objet *objet) {
    chateau->placeDansSalle(position, objet);
}

Salle *Jeu::getSalle(std::pair<unsigned int, unsigned int> position) const {
    if (position.first > chateau->width || position.second > chateau->length) {
        cout << "ERROR WITH SALLE COORDINATES\n";
        return nullptr;
    }
    return chateau->map[position.first][position.second];

}

void Jeu::moveJoueurtoSalle(Joueur *joueur, Salle *salle) {
    pair<int, int> position = getSallePosition(salle->getId());
    moveJoueur(joueur, position.first, position.second);
}

void Jeu::spotLast(){
    if (joueurs.size() < nombreDeJoueurs / 2){
        for(unsigned int i = 0; i < joueurs.size(); i++){
            utilities::display("Le joueur " + joueurs[i]->getName() + " est dans la salle " + 
            to_string(getSalle(joueurs[i]->getPersonnage()->getPosition())->getId()) + "\n");
        }
    }
}