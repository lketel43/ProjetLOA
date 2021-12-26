//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Salle.hpp"

using namespace std;

Salle::Salle(int num) : id(num) {

}


int Salle::numOfPlayers() const {
    return joueurs.size();
}

int Salle::numOfObjects() const {
    return objets.size();
}

int Salle::getId() const {
    return id;
}

void Salle::addPlayer(Joueur *j) {
    joueurs.push_back(j);

}

//TODO: need to verify it works
void Salle::removePlayer(Joueur *joueur) {
    for (long unsigned int i = 0; i < joueurs.size(); i++) {
        if (joueurs[i] == joueur) {
            joueurs.erase(joueurs.begin() + i);
            return;
        }
    }

}

//TODO: add overload of << in objet
ostream &operator<<(ostream &out, Salle *salle) {
    out<<"Vous êtes actuellement dans la salle "<<salle->id<<"."<<endl;
    out<<"Elle contient les objets suivants:"<<endl;
    for(unsigned int i = 0; i<salle->objets.size(); i++)
        out<<"Objet "<<i<<":"<<endl<<salle->objets[i]<<endl;

    out<<"Elle contient les joueurs suivants:"<<endl;

    for(unsigned int i = 0; i<salle->joueurs.size(); i++)
        out<<salle->joueurs.size();

   return out;

}

void Salle::placeObject(Objet * object) {
objets.push_back(object);

}
