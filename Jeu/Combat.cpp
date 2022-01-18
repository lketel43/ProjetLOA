#include "Combat.hpp"
#include "../Utilities/utilities.hpp"

Combat::Combat(Joueur* _j1, Joueur* _j2): j1(_j1), j2(_j2) {}

void Combat::commencerCombat(){
    utilities::display("######## Un combat entre " + this->j1->getName() + " et " + this->j2->getName() + " a commencé. ########\n");
    while(this->j1->getPersonnage()->getSante() > 0 && this->j2->getPersonnage()->getSante() > 0){
        this->j1->tourCombat(this->j2);
        this->j2->tourCombat(this->j1);
    }
    if(this->j1->getPersonnage()->getSante() <= 0 && this->j2->getPersonnage()->getSante() <= 0) utilities::display("Le combat est terminé. Les deux joueurs sont morts");
    if(this->j1->getPersonnage()->getSante() <= 0) utilities::display("Le combat est terminé. " + this->j1->getName() + " a perdu.");
    else utilities::display("Le combat est terminé. " + this->j2->getName() + " a perdu.");
}

int Combat::calculDegatsPhysique(const Joueur* attaquant, const Joueur* defenseur){
    int deg = attaquant->getPersonnage()->getAttaquePhysique();
    for(unsigned int i = 0; i < attaquant->getPersonnage()->getEquipement().size(); i++){
        deg += ((dynamic_cast<Arme*>(attaquant->getPersonnage()->getEquipement()[i]))->getDommagePhysique() / 100) * attaquant->getPersonnage()->getAttaquePhysique();
    }
    if(deg > 100) deg = 100;
    int res = defenseur->getPersonnage()->getResistancePhysique();
    for(unsigned int i = 0; i < defenseur->getPersonnage()->getEquipement().size(); i++){
        res += ((dynamic_cast<Arme*>(defenseur->getPersonnage()->getEquipement()[i]))->getDefensePhysique() / 100) * attaquant->getPersonnage()->getResistancePhysique();
    }
    if(res > 100) res = 100;
    int degatReel = deg - (deg * (res / 100));
    int coutCritique = utilities::bernouilli(attaquant->getPersonnage()->getHabilete() / 100) * deg * 0.5;
    return degatReel + coutCritique;
}

int Combat::calculDegatsMagique(const Joueur* attaquant, const Joueur* defenseur){
    int deg = attaquant->getPersonnage()->getAttaqueMagique();
    for(unsigned int i = 0; i < attaquant->getPersonnage()->getEquipement().size(); i++){
        deg += ((dynamic_cast<Arme*>(attaquant->getPersonnage()->getEquipement()[i]))->getDommageMagique() / 100) * attaquant->getPersonnage()->getAttaqueMagique();
    }
    if(deg > 100) deg = 100;
    int res = defenseur->getPersonnage()->getResistanceMagique();
    for(unsigned int i = 0; i < defenseur->getPersonnage()->getEquipement().size(); i++){
        res += ((dynamic_cast<Arme*>(defenseur->getPersonnage()->getEquipement()[i]))->getDefenseMagique() / 100) * attaquant->getPersonnage()->getResistanceMagique();
    }
    if(res > 100) res = 100;
    int degatReel = deg - (deg * (res / 100));
    int coutCritique = utilities::bernouilli(attaquant->getPersonnage()->getHabilete() / 100) * deg * 0.5;
    return degatReel + coutCritique;
}