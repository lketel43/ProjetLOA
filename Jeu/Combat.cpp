#include "Combat.hpp"
#include "../Utilities/Utilities.cpp"

Combat::Combat(Joueur* _j1, Joueur* _j2): j1(_j1), j2(_j2) {}

void Combat::commencerCombat(){
    utilities::display("######## Un combat entre " + this->j1->getName() + " et " + this->j2->getName() + " a commencé. ########\n");
    while(this->j1->getPersonnage()->getSante() > 0 && this->j2->getPersonnage()->getSante() > 0){
        this->j1->tourCombat(this->j2);
        this->j2->tourCombat(this->j1);
    }
    if(this->j1->getPersonnage()->getSante() <= 0) utilities::display("Le combat est terminé. " + this->j1->getName() + " a perdu.");
    else utilities::display("Le combat est terminé. " + this->j2->getName() + " a perdu.");
}

void Combat::tour(){
    
}

int Combat::calculDegatsPhysique(const Joueur* attaquant, const Joueur* defenseur){
    return 0;
}

int Combat::calculDegatsMagique(const Joueur* attaquant, const Joueur* defenseur){
    return 0;
}