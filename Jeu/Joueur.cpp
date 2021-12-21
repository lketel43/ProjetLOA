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