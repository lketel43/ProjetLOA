//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Joueur.hpp"
using namespace std;

Joueur::Joueur(const string name, Personnage * personnage1, const bool autom): nom(name), personnage(personnage1), automatise(autom) {
    //Le joueur n'est pas placé encore
    position.first = position.second = -1;
    score = 0;
}

void Joueur::setPosition(const int &x,const int &y){
    position.first = x;
    position.second = y;
}

Joueur::~Joueur(){
  delete personnage;
}

std::string Joueur::getName() const{
    return nom;
}

bool Joueur::isPlaced() const {

    return (position.first != -1 && position.second != -1);
}

pair<int, int> Joueur::getPosition() const {
    return position;
}

ostream& operator<<(ostream& out, Joueur* joueur){
    out<<"Joueur "<<joueur->getName()<<endl;
    out<<joueur->personnage;
    return out;
}

void Joueur::jeter(int index){
    
    this->personnage->setEquipement(index, nullptr);
}