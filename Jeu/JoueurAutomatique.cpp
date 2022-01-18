#include "JoueurAutomatique.hpp"
#include "../Utilities/utilities.hpp"

using namespace std;

JoueurAutomatique::JoueurAutomatique(std::string _name) : Joueur(_name, true) {}

JoueurAutomatique::~JoueurAutomatique() = default;

void JoueurAutomatique::tourCombat(const Joueur *j) const {
    utilities::display("C'est le tour de " + this->nom + " de joueur\n");
    int degatsP = Combat::calculDegatsPhysique(this, j);
    int degatsM = Combat::calculDegatsMagique(this, j);
    j->getPersonnage()->subitAttaque(degatsP + degatsM);
    utilities::display(this->nom + " vous inflige " + std::to_string(degatsP + degatsM) + " point de dégâts\n");
    utilities::display("Il vous reste " + to_string(j->getPersonnage()->getSante()) + " points de vie\n");
}

void JoueurAutomatique::consulterSacEtEquipement(Jeu *) {

}

void JoueurAutomatique::pickUpObjects(Jeu *) {

}

int JoueurAutomatique::choosePersonnage(std::vector<std::pair<Personnage *, int>> personnagesDisponiblesEtFrequences) {
    int min = personnagesDisponiblesEtFrequences[0].second;
    unsigned int choice = 1;
    for (unsigned int i = 1; i < personnagesDisponiblesEtFrequences.size(); i++) {
        if (min > personnagesDisponiblesEtFrequences[i].second) {
            min = personnagesDisponiblesEtFrequences[i].second;
            choice = i + 1;
        }
    }
    return choice;
}

void JoueurAutomatique::endTurn(Jeu *jeu) {
    Salle *salle = jeu->getSalle(position);
    vector<Salle *> neighbors = salle->getNeighbors();

    //choix neighbors.size() veut dire rester sur place
    int choice = utilities::random(0, neighbors.size());

    if (choice != neighbors.size())
        jeu->moveJoueurtoSalle(this, neighbors[choice]);

}
