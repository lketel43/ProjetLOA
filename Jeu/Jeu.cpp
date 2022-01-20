

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


vector<Objet *> Jeu::objetsPossibles{initVecteurObjets()};

void Jeu::initVecteursJoueurs() {
    for (int i = 0; i < nombreJoueurNonAutomatise; i++) {
        joueurs.push_back(new JoueurManuel(to_string(i + 1)));
    }
    for (int i = nombreJoueurNonAutomatise; i < nombreDeJoueurs; i++) {
        joueurs.push_back(new JoueurAutomatique(to_string(i + 1)));
    }
}


//TODO: make it check that value of joueurs> joueurNonAuto
Jeu::Jeu(int joueurNonAuto, int joueurs, unsigned int chateauLength, unsigned int chateauWidth)
        : nombreDeJoueurs(joueurs), nombreJoueurNonAutomatise(joueurNonAuto) {
    chateau = new Chateau(chateauWidth, chateauLength);
    objectFactory = new ObjectFactory(objetsPossibles);
    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge
    initVecteurPersonnages();
    initVecteursJoueurs();
}

Jeu::Jeu() : nombreDeJoueurs(5), nombreJoueurNonAutomatise(1) {
    chateau = new Chateau(4, 4);
    objectFactory = new ObjectFactory(objetsPossibles);
    //Si jamais on ajoute un nouveau type de personnages, on a qu'à ajouter ça ici,
    // et effectuer un changement dans la fonction forge
    initVecteurPersonnages();
    initVecteursJoueurs();

}

vector<Joueur*> Jeu::getJoueurs() const{
    return joueurs;
}

void Jeu::removeJoueur(Personnage* mort) {
    for(unsigned int i = 0; i < joueurs.size(); i++){
        if(&(*joueurs[i]->getPersonnage()) == &(*mort)){
            joueurs.erase(joueurs.begin() + i);
            break;
        }
    }
}

void Jeu::initJoueurs() {
    int choice;
    //TODO: ecrire text du début
    utilities::display("Introductory text: needs completion \n");

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


void Jeu::lancePartie() {
    initJoueurs();
    placeJoueurs();
    placeObjets();

    //joueurs[0]->getPersonnage()->setHabilete(90);
    //Combat* c = new Combat(joueurs[0], joueurs[1]);
    //c->commencerCombat();
    // TEST COMBAT
    while (true) {
        for (unsigned int i = 0; i < joueurs.size(); i++) {
            tour(joueurs[i]);
        }
    }
}


void Jeu::placeJoueurs() {
    int x, y;

    //Vrais joueurs sont placés de manière random
    for (int i = 0; i < nombreJoueurNonAutomatise; i++) {
        //TODO: careful, might be source of slow execution
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
        //TODO: make joueur display its stats
        int choice;
        do {
            utilities::display("Que voulez-vous faire?\n");
            utilities::display("1. Consulter/modifier votre sac et votre équipement.\n");
            utilities::display("2. Ramasser des objets.\n");
            utilities::display("3. Commencer un combat. \n");
            utilities::display("4. Finir votre tour. \n");

            choice = utilities::validateRange( 1, 4);
            //TODO: take into consideration that some options might not be viable (ex. can't battle if nobody's there, etc.)
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
                    //TODO: les degats sont égaux
                    //TODO: peut-être montrer les stats des joueurs ennemies (en incluant les armes qu'ils ont)
                    vector<pair<Joueur *, int> > ennemies{salle->displayEnnemi(joueur)};
                    utilities::display("Choisissez un ennemi à combattre:\n");
                    // Faire le le choix
                    int choiceEnnemi;
                    choiceEnnemi = utilities::validateRange(1, salle->nbEnnemi());
                    // Créer le combat et le lancer
                    int index = ennemies[choiceEnnemi - 1].second;
                    if(joueur->getPersonnage()->getHabilete() >= salle->getJoueur()[index]->getPersonnage()->getHabilete()){
                        Combat c{joueur, salle->getJoueur()[index]};
                        c.commencerCombat();
                    }
                    else{
                        Combat c{salle->getJoueur()[index], joueur};
                        c.commencerCombat();
                    }
                    

                    //Mort éventuelle des joueurs
                    Joueur* m1 = joueur->mort(this);
                    Joueur* m2 = salle->getJoueur()[index]->mort(this);
                    if(m2 != nullptr){
                        for(unsigned int i = 0; i < m2->getPersonnage()->getSac().size(); i++){
                            salle->placeObject(m2->getPersonnage()->getSac()[i]);
                        }
                        for(unsigned int i = 0; i < m2->getPersonnage()->getEquipement().size(); i++){
                            salle->placeObject(m2->getPersonnage()->getEquipement()[i]);
                        }
                        delete m2;
                    }
                    if(m1 != nullptr){

                    }
                    break;
                }
                case 4:
                    if (salle->hasNoOtherPlayers()){
                        //rajouter objets dans la salle qu'il va quitter
                        salle->placeObject(objectFactory->produce());
                        salle->placeObject(objectFactory->produce());
                        joueur->endTurn(this);

                    }


                    else {
                        utilities::display(
                                "Il vous reste encore des ennemis à combattre ici.\nVous ne pouvez pas finir votre tour maintenant.\n");
                    }
                    break;
                default:
                    utilities::display("Error! choice of action is not a valid one.");
            }

        } while (choice != 4);

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