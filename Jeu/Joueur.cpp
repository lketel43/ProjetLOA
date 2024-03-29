//
// Created by Laila ElKoussy on 12/20/21.
//

#include <iostream>
#include "Joueur.hpp"
#include "Map/Salle.hpp"
#include "Jeu.hpp"
#include "../Objets/Clef.hpp"
#include "../Objets/Potion.hpp"
#include "../Utilities/utilities.hpp"

using namespace std;

Joueur::Joueur(const string name, const bool autom) : personnage(nullptr),
                                                      automatise(autom), nom(name) {
    score = 0;
}

Joueur::~Joueur() {
    if(personnage != nullptr) delete personnage;
}

std::string Joueur::getName() const {
    return nom;
}

Personnage *Joueur::getPersonnage() const {
    return this->personnage;
}

ostream &operator<<(ostream &out, Joueur *joueur) {
    out << "Joueur " << joueur->getName() << endl;
    out << joueur->personnage;
    return out;
}

bool Joueur::isAutomatise() const {
    return automatise;
}

bool Joueur::ramasser(Objet *o) {
    if (this->personnage->isSacFull()) {
        utilities::display("Sac plein, veuillez jeter un objet.\n");
        return false;
    } else {
        this->personnage->addToSac(o);
        return true;
    }
}

bool Joueur::equiper(Objet *o) {
    if (!o->isEquipable()) {
        utilities::display("Cet objet n'est pas équipable.\n");
        return false;
    }
    if (this->personnage->isEquipementFull()) {
        utilities::display("Équipement plein veuillez déséquiper un objet.\n");
        return false;
    } else {
        this->personnage->addToEquipement(o);
        return true;
    }
}

bool Joueur::desequiper(int index) {
    if (this->personnage->isSacFull()) {
        utilities::display("Votre sac est plein. Veuillez vider votre sac, ou jeter l'objet.\n");
        return false;
    }
    Objet *o = this->personnage->getEquipement()[index];
    this->personnage->removeFromEquipement(index);
    this->personnage->addToSac(o);
    utilities::display("Cette arme est maintenant dans votre sac\n");
    return true;
}

Objet *Joueur::jeterDeEquipement(int index) {
    Objet *ret = this->personnage->getEquipement()[index];
    this->personnage->removeFromEquipement(index);
    return ret;
}

void Joueur::utiliserClef(Clef *c, Jeu *jeu) {
    int choice;
    if (!c->isUtilisable()) {
        utilities::display("Cet objet n'est pas utilisable.\n");
        return;
    }
    if (c->getIdType() == IDTYPE_CLEF) {
        utilities::display("Vous avez choisi d'utiliser une clef de téléportation.\n");
        utilities::display("Pour rappel, nous vous montrons la carte avec votre position.\n");
        jeu->displayMap(this);
        utilities::display("Quelle salle choisissez vous?\n");
        choice = utilities::validateRange( 0, jeu->getNumberOfSalles() - 1);

        pair<int, int> pair1 = jeu->getSallePosition(choice);

        c->utiliser(jeu, this, pair1.first, pair1.second);
        utilities::display("Vous avez bien été transporté dans la salle " + to_string(choice) + ".\n");
        jeu->getSalle(pair1)->display();
    }
    int index = 0;
    for(long unsigned int i = 0; i < this->personnage->getSac().size(); i++){
        if(this->personnage->getSac()[i] == c){
            index = i;
            break;
        }
    }
    delete c;
    this->personnage->removeFromSac(index);

}



Objet *Joueur::jeterDeSac(int index) {
    Objet *ret = this->personnage->getSac()[index];
    this->personnage->removeFromSac(index);
    return ret;
}

void Joueur::setPersonnage(Personnage *_personnage) {
    this->personnage = _personnage;
}