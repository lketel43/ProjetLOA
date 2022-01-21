//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Potion.hpp"
#include "../Utilities/utilities.hpp"

using namespace std;

Potion::Potion(std::string _nom, int _rarete, float _boost, std::string _type) : Objet::Objet(_nom, _rarete, false,
                                                                                              true, 1), boost(_boost),
                                                                                 type(_type), poison(_boost < 0) {
}

std::string Potion::getType() const {
    return this->type;
}

float Potion::getBoost() const {
    return this->boost;
}

void Potion::display() const {
    utilities::display("Nom: " + nom + "\nRareté: " + to_string(rarete) +
                       "\nBoost: " + type + " " + ((boost > 0) ? "+" : "") + to_string(boost) + "\n");

}

string Potion::toString() const {
    return "Nom: " + nom + "\nRareté:" + to_string(rarete) +
           "\nBoost: " + type + " " + ((boost > 0) ? "+" : "") + to_string(boost) + "\n";
}

bool Potion::getPoison() const {
    return this->poison;
}

Potion *Potion::copy() {
    return new Potion(nom, rarete, boost, type);
}

Potion::~Potion() = default;

bool Potion::isArmeDeDefense() const {
    return false;
}

bool Potion::isArmeDattaque() const {
    return false;
}