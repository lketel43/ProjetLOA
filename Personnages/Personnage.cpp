//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Personnage.hpp"

using namespace std;


Personnage::Personnage(string n, int aP, int aM, int rP, int rM) : nom(n), attaquePhysique(aP), attaqueMagique(aM),
                                                                   resistanceMagique(rM), resistancePhysique(rP) {
    for (int i = 0; i < TAILLE_SAC; i++) {
        sac[i] = nullptr;
    }
    for (int i = 0; i < 2; i++) {
        equipement[i] = nullptr;
    }
}

//TODO: a voir si on change la fonction attaque pour prendre en compte habileté, santé etc.
pair<int, int> Personnage::attaque() {
    pair<int, int> pair(attaquePhysique, attaqueMagique);
    return pair;
}

void Personnage::subitAttaque(pair<int, int> &pair) {

    //Prevoie si la resistance  est superieure à l'attaque
    sante -= ((pair.first - resistancePhysique) > 0) ? pair.first - resistancePhysique : 0;
    sante -= ((pair.second - resistanceMagique) > 0) ? pair.second - resistanceMagique : 0;

}

string Personnage::getName() {
    return nom;
}

string Personnage::getStats() {
    string stat;
    stat = "Attaque Physique: " + std::to_string(attaquePhysique) + "\n";
    stat += "Attaque Magique: " + std::to_string(attaqueMagique) + "\n";
    stat += "Résistance Physique: " + std::to_string(resistancePhysique) + "\n";
    stat += "Résistance Magique: " + std::to_string(resistanceMagique) + "\n";

    return stat;
}

Objet **Personnage::getSac() {
    return this->sac;
}

void Personnage::setSac(int index, Objet *o) {
    this->sac[index] = o;
}

ostream &operator<<(ostream &out, Personnage *personnage) {

    out << "Personnage " << personnage->nom << endl;
    out << "Santé: " << personnage->sante << endl
        << "Habileté: " << personnage->habilite << endl
        << "Attaque Physique: " << personnage->attaquePhysique << endl
        << "Attaque Magique: " << personnage->attaqueMagique << endl
        << "Résistance Physique: " << personnage->resistancePhysique << endl
        << "Résistance Magique:" << personnage->resistanceMagique << endl;

    return out;
}

bool Personnage::isSacFull() {
    for (int i = 0; i < TAILLE_SAC; i++) {
        if (this->sac[i] == nullptr) return false;
    }
    return true;
}

bool Personnage::isEquipementFull() {
    for (int i = 0; i < TAILLE_SAC; i++) {
        if (this->equipement[i] == nullptr) return false;
    }
    return true;
}

Objet **Personnage::getEquipement() {
    return this->equipement;
}

void Personnage::setEquipement(int index, Objet *o) {
    this->equipement[index] = o;
}

void Personnage::setSante(int n) {
    int diff = MAX_SANTE - this->sante;
    if (diff < n) this->sante = MAX_SANTE;
    else this->sante += n;
}

void Personnage::setHabilete(int n) {
    this->habilite += n;
}

void Personnage::setAttatquePhysique(int n) {
    this->attaquePhysique += n;
}

void Personnage::setAttaqueMagique(int n) {
    this->attaqueMagique += n;
}

void Personnage::setResistancePhysique(int n) {
    this->resistancePhysique += n;
}

void Personnage::setResistanceMagique(int n) {
    this->resistanceMagique += n;
}

Personnage::~Personnage() {
    for (int i = 0; i < TAILLE_SAC; i++)
        if (sac[i] != nullptr)
            delete sac[i];

    for (int i = 0; i < TAILLE_EQ; i++)
        if (equipement[i] != nullptr)
            delete equipement[i];

}