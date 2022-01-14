//
// Created by Laila ElKoussy on 12/20/21.
//

#include <iostream>
#include "Joueur.hpp"
#include "Map/Salle.hpp"
#include "Jeu.hpp"
#include "../Objets/Clef.hpp"
#include "../Objets/Potion.hpp"
#include "../Utilities/Utilities.cpp"

using namespace std;

Joueur::Joueur(const string name, Personnage *personnage1, const bool autom) : nom(name), personnage(personnage1),
                                                                               automatise(autom) {
    //Le joueur n'est pas placé encore
    position.first = position.second = -1;
    score = 0;
}

void Joueur::setPosition(const int &x, const int &y) {
    position.first = x;
    position.second = y;
}

Joueur::~Joueur() {
    delete personnage;
}

std::string Joueur::getName() const {
    return nom;
}

bool Joueur::isPlaced() const {

    return (position.first != -1 && position.second != -1);
}

pair<int, int> Joueur::getPosition() const {
    return position;
}

ostream &operator<<(ostream &out, Joueur *joueur) {
    out << "Joueur " << joueur->getName() << endl;
    out << joueur->personnage;
    return out;
}

bool Joueur::isAutomatise() const {
    return automatise;
}

void Joueur::ramasser(Objet *o) {
    if (this->personnage->isSacFull()) {
        cout << "Sac plein, veuillez jeter un objet.\n";
    } else {
        this->personnage->addToEquipement(o);
    }
}

void Joueur::equiper(Objet *o) {
    if (!o->isEquipable()) {
        cout << "Cet objet n'est pas équipable.\n";
        return;
    }
    if (this->personnage->isEquipementFull()) {
        cout << "Équipement plein veuillez déséquiper un objet.\n";
    } else {
        this->personnage->addToEquipement(o);
    }
}

void Joueur::desequiper(int index) {
    if (this->personnage->isSacFull()) {
        utilities::display("Votre sac est plein. Veuillez vider votre sac, ou jeter l'objet.\n");
        return;
    }
    Objet *o = this->personnage->getEquipement()[index];
    this->personnage->removeFromEquipement(index);
    this->personnage->addToSac(o);
    utilities::display("Cette arme est maintenant dans votre sac\n");
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
        cin >> choice;
        choice = utilities::validateRange(choice, 0, jeu->getNumberOfSalles() - 1);

        pair<int, int> pair1 = jeu->getSallePosition(choice);

        c->utiliser(jeu, this, pair1.first, pair1.second);
        utilities::display("Vous avez bien été transporté dans la salle " + to_string(choice) + ".\n");
    }
}

void Joueur::utiliserPotion(Potion *p) {
    if (!p->isUtilisable()) {
        utilities::display("Cet objet n'est pas utilisable.\n");
        return;
    }
    if (p->getIdType() == IDTYPE_POTION) {
        utilities::display("Vous avez choisi d'utiliser une potion de type" + p->getType() + ".\n");
        if (p->getType() == "sante") {
            this->personnage->setSante(p->getBoost());
        }
        if (p->getType() == "habilete") {
            this->personnage->setHabilete(p->getBoost());
        }
        if (p->getType() == "attaquePhysique") {
            this->personnage->setAttaquePhysique(p->getBoost());
        }
        if (p->getType() == "attaqueMagique") {
            this->personnage->setAttaqueMagique(p->getBoost());
        }
        if (p->getType() == "resistancePhysique") {
            this->personnage->setResistancePhysique(p->getBoost());
        }
        if (p->getType() == "resistanceMagique") {
            this->personnage->setResistanceMagique(p->getBoost());
        }
        utilities::display("Voici vos statistiques après cette potion:\n");
        utilities::display(this->personnage->getStats());
    }
}


Objet *Joueur::jeterDeSac(int index) {
    Objet *ret = this->personnage->getSac()[index];
    this->personnage->removeFromSac(index);
    return ret;
}
