#include "JoueurAutomatique.hpp"
#include "../Utilities/Utilities.cpp"

JoueurAutomatique::JoueurAutomatique(std::string _name, Personnage * _personnage): Joueur(_name, _personnage, true) {}

void JoueurAutomatique::tourCombat(const Joueur* j) const{
    utilities::display("C'est le tour de " + this->nom + " de joueur\n");
    int degatsP = Combat::calculDegatsPhysique(this, j);
    int degatsM = Combat::calculDegatsMagique(this, j);
    j->getPersonnage()->subitAttaque(degatsP + degatsM);
}