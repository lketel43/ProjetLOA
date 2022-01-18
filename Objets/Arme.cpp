//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Arme.hpp"
#include "../Utilities/utilities.hpp"

using namespace std;

Arme::Arme(std::string _nom, int _rarete, float _dommagePhysique, float _dommageMagique, float _defensePhysique,
           float _defenseMagique) :
        Objet::Objet(_nom, _rarete, true, false, IDTYPE_ARME),
        dommagePhysique(_dommagePhysique), dommageMagique(_dommageMagique),
        defensePhysique(_defensePhysique), defenseMagique(_defenseMagique) {

}

float Arme::getDommagePhysique() const {
    return this->dommagePhysique;
}

float Arme::getDommageMagique() const {
    return this->dommageMagique;
}

float Arme::getDefensePhysique() const {
    return this->defensePhysique;
}

float Arme::getDefenseMagique() const {
    return this->defenseMagique;
}


void Arme::display() const {
    utilities::display("Nom: " + nom + "\nRareté: " + to_string(rarete) + "\nDommage Physique: " + to_string(dommagePhysique) +
                       "\nDommage Magique: " + to_string(dommageMagique) + "\nDéfense Physique:" + to_string(defensePhysique) +
                       "\nDéfense Magique: "
                       + to_string(defenseMagique) + "\n");

}

Arme *Arme::copy() {
    return new Arme(nom, rarete, dommagePhysique, dommageMagique, defensePhysique, defenseMagique);
}

string Arme::toString() const {
    return "Nom: " + nom + "\nRareté: " + to_string(rarete) + "\nDommage Physique: " + to_string(dommagePhysique) +
           "\nDommage Magique: " + to_string(dommageMagique) + "\nDéfense Physique:" + to_string(defensePhysique) +
           "\nDéfense Magique: "
           + to_string(defenseMagique) + "\n";
}

Arme::~Arme() = default;