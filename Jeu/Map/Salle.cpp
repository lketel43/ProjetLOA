//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Salle.hpp"
#include "../../Utilities/Utilities.cpp"
#include "../Joueur.hpp"

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

vector<Joueur*> Salle::getJoueur() const{
    return this->joueurs;
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

Objet* Salle::removeObject(int index) {
    Objet * object = objets[index];
    objets.erase(objets.begin() + index);
    return object;
}

void Salle::displayObjects() const {
    for (unsigned int i = 0; i < objets.size(); i++) {
        utilities::display( to_string(i+1) + ".");
        objets[i]->display();
        utilities::display("\n");
    }

}

bool Salle::hasNoObjects() const {
    return objets.empty();
}

bool Salle::hasNoOtherPlayers() const {
    return (joueurs.size() > 1);
}

void Salle::display() const {
    utilities::display("Vous êtes actuellement dans la salle " + to_string(id) +
                       ".\n");
    utilities::display("Elle contient les objets suivants:\n");

    for (unsigned int i = 0; i < objets.size(); i++) {
        utilities::display("Objet " + to_string(i+1) + ":\n");
        objets[i]->display();
    }

    utilities::display("Elle contient les joueurs suivants:\n");

    for (unsigned int i = 0; i < joueurs.size(); i++)
        utilities::display("Joueur " + joueurs[i]->getName() +"\n");


}

void Salle::displayEnnemi() const{
    if(joueurs.size() <= 1) return;
    utilities::display("Les ennemis suivants sont présents\n");
    for(unsigned int i = 1; i < joueurs.size(); i++){
        utilities::display(to_string(i) + ". " + joueurs[i]->getPersonnage()->getName() + "\n" + joueurs[i]->getPersonnage()->getStats());
    }
}

int Salle::nbEnnemi() const{
    return this->joueurs.size() - 1;
}

void Salle::placeObject(Objet *object) {
    objets.push_back(object);

}

Salle *Salle::nord() const {
    return neighbors[north];
}

Salle *Salle::sud() const {
    return neighbors[south];
}

Salle *Salle::est() const {
    return neighbors[east];
}

Salle * Salle::ouest() const {
    return neighbors[west];
}

Salle::~Salle(){
    for( long unsigned int i = 0; i < objets.size(); i++){
        delete objets[i];
    }

    for(long unsigned int i = 0; i< joueurs.size(); i++){
        if(joueurs[i] != nullptr)
            delete joueurs[i];
    }
}