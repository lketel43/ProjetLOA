//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Salle.hpp"

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
            joueurs.erase(joueurs.begin()+i);
            return;
        }
    }

}
