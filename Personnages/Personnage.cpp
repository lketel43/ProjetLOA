//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Personnage.hpp"
#include "../Utilities/Utilities.cpp"

using namespace std;


Personnage::Personnage(string n, int aP, int aM, int rP, int rM) : nom(n), attaquePhysique(aP), attaqueMagique(aM),
                                                                   resistanceMagique(rM), resistancePhysique(rP) {
}

//TODO: a voir si on change la fonction attaque pour prendre en compte habileté, santé etc.
pair<int, int> Personnage::attaque() {
    pair<int, int> pair(attaquePhysique, attaqueMagique);
    return pair;
}

void Personnage::subitAttaque(int d) {
    this->sante -= d;
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

vector<Objet*> Personnage::getSac() {
    return this->sac;
}

void Personnage::addToSac(Objet *o) {
    this->sac.push_back(o);
}

void Personnage::removeFromSac(int i){
    sac.erase(sac.begin() + i);
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
    if(this->sac.size() == TAILLE_SAC) return true;
    return false;
}

void Personnage::displaySac(){
    if(this->sac.empty()){
        utilities::display("Votre sac est vide\n");
    }
    else{
        utilities::display("Votre sac contient:\n");
        for(unsigned int i = 0; i < this->sac.size(); i++){
            utilities::display(this->sac[i]->getNom() + "\n");
        }
    }
}

bool Personnage::isEquipementFull() {
    if(this->sac.size() == TAILLE_EQ) return true;
    return false;
}

vector<Objet*> Personnage::getEquipement() {
    return this->equipement;
}

void Personnage::addToEquipement(Objet *o) {
    this->equipement.push_back(o);
}

void Personnage::removeFromEquipement(int i){
    equipement.erase(equipement.begin() + i);
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