//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Personnage.hpp"
#include "../Utilities/utilities.hpp"

using namespace std;


Personnage::Personnage(string n, int aP, int aM, int rP, int rM) : nom(n), attaquePhysique(aP), attaqueMagique(aM),
                                                                    resistancePhysique(rP),resistanceMagique(rM) {
    position.first = position.second = -1;
}

//TODO: a voir si on change la fonction attaque pour prendre en compte habileté, santé etc.
pair<int, int> Personnage::attaque() {
    pair<int, int> pair(attaquePhysique, attaqueMagique);
    return pair;
}

void Personnage::subitAttaque(int d) {
    if(this->sante - d < 0) this->sante = 0;
    else this->sante -= d;
}

string Personnage::getName() const{
    return nom;
}

int Personnage::getSante() const{
    return this->sante;
}

int Personnage::getHabilete() const{
    return this->habilite;
}

int Personnage::getAttaquePhysique() const{
    return this->attaquePhysique;
}

int Personnage::getAttaqueMagique() const{
    return this->attaqueMagique;
}

int Personnage::getResistancePhysique() const{
    return this->resistancePhysique;
}

int Personnage::getResistanceMagique() const{
    return this->resistanceMagique;
}

std::pair<int, int> Personnage::getPosition() const{
    return this->position;
}

string Personnage::getStats() const{
    string stat;
    stat = "Attaque Physique: " + std::to_string(attaquePhysique) + "\n";
    stat += "Attaque Magique: " + std::to_string(attaqueMagique) + "\n";
    stat += "Résistance Physique: " + std::to_string(resistancePhysique) + "\n";
    stat += "Résistance Magique: " + std::to_string(resistanceMagique) + "\n";

    return stat;
}

vector<Objet*> Personnage::getSac() const{
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

bool Personnage::isSacFull() const{
    if(this->sac.size() == TAILLE_SAC) return true;
    return false;
}

void Personnage::displaySac() const{
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

bool Personnage::isEquipementFull() const{
    if(this->equipement.size() < TAILLE_EQ) return false;
    return true;
}

bool Personnage::isPlaced() const {

    return (position.first != -1 && position.second != -1);
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
    if(this->habilite + n > 100) this->habilite = 100;
    if(this->habilite + n < 0) this->habilite = 0;
    else this->habilite += n;
}

void Personnage::setAttaquePhysique(int n) {
    this->attaquePhysique += n;
}

void Personnage::setAttaqueMagique(int n) {
    this->attaqueMagique += n;
}

void Personnage::setResistancePhysique(int n) {
    if(this->resistancePhysique + n > 100) this->resistancePhysique = 100;
    if(this->resistancePhysique + n < 0) this->resistancePhysique = 0;
    else this->resistancePhysique += n;
}

void Personnage::setResistanceMagique(int n) {
    if(this->resistanceMagique + n > 100) this->resistanceMagique = 100;
    if(this->resistanceMagique + n < 0) this->resistanceMagique = 0;
    else this->resistanceMagique += n;
}

void Personnage::setPosition(int x, int y){
    position.first = x;
    position.second = y;
}

Personnage::~Personnage() = default;

Potion* Personnage::hasPotionBoostSante() const{
    for(unsigned int i = 0; i < this->sac.size(); i++){
        if(this->sac[i]->getIdType() == IDTYPE_POTION){
            if(dynamic_cast<Potion*>(this->sac[i])->getType() == "sante") return dynamic_cast<Potion*>(this->sac[i]);
        }
    }
    return nullptr;
}

Potion* Personnage::hasPotionPoison() const{
    for(unsigned int i = 0; i < this->sac.size(); i++){
        if(this->sac[i]->getIdType() == IDTYPE_POTION){
            if(dynamic_cast<Potion*>(this->sac[i])->getPoison()) return dynamic_cast<Potion*>(this->sac[i]);
        }
    }
    return nullptr;
}

Potion* Personnage::hasPotionBoost() const{
    for(unsigned int i = 0; i < this->sac.size(); i++){
        if(this->sac[i]->getIdType() == IDTYPE_POTION){
            if(!dynamic_cast<Potion*>(this->sac[i])->getPoison()) return dynamic_cast<Potion*>(this->sac[i]);
        }
    }
    return nullptr;
}