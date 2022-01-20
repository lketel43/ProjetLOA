#include "Combat.hpp"
#include "../Utilities/utilities.hpp"

Combat::Combat(Joueur* _j1, Joueur* _j2): j1(_j1), j2(_j2) {}

void Combat::commencerCombat(){
    utilities::display("######## Un combat entre " + this->j1->getName() + " et un ennemi de type " + this->j2->getPersonnage()->getName() + " a commencé. ########\n");
    while(true){
        this->j1->tourCombat(this->j2);
        if(this->j2->getPersonnage()->getSante() <= 0) break;

        this->j2->tourCombat(this->j1);
        if(this->j1->getPersonnage()->getSante() <= 0) break;
    }
    if(this->j1->getPersonnage()->getSante() <= 0){
        utilities::display("Le combat est terminé. Le joueur " + this->j1->getName() + " a perdu.\n\n");
    }
    else{
        utilities::display("Le combat est terminé. Le joueuer " + this->j2->getName() + " a perdu.\n\n");
    }
}

int Combat::calculDegatsPhysique(const Joueur* attaquant, const Joueur* defenseur){
    int deg = attaquant->getPersonnage()->getAttaquePhysique();
    for(unsigned int i = 0; i < attaquant->getPersonnage()->getEquipement().size(); i++){
        deg += utilities::calcPercentage(attaquant->getPersonnage()->getAttaquePhysique(), 
                                        (dynamic_cast<Arme*>(attaquant->getPersonnage()->getEquipement()[i]))->getDommagePhysique());
    }
    if(deg > 100) deg = 100;
    int res = defenseur->getPersonnage()->getResistancePhysique();
    for(unsigned int i = 0; i < defenseur->getPersonnage()->getEquipement().size(); i++){
        res += utilities::calcPercentage(attaquant->getPersonnage()->getResistancePhysique() ,
                                    (dynamic_cast<Arme*>(defenseur->getPersonnage()->getEquipement()[i]))->getDefensePhysique());
    }
    if(res > 100) res = 100;
    int degatReel = deg - utilities::calcPercentage(deg, res);
    int coupCritique = utilities::bernouilli(attaquant->getPersonnage()->getHabilete() / 100.0) * deg * 0.5;
    if(coupCritique > 0) utilities::display("Un coup critique physique est infligé, l'attaque augmente de " + std::to_string(coupCritique) + ".\n");
    return degatReel + coupCritique;
}

int Combat::calculDegatsMagique(const Joueur* attaquant, const Joueur* defenseur){
    int deg = attaquant->getPersonnage()->getAttaqueMagique();
    for(unsigned int i = 0; i < attaquant->getPersonnage()->getEquipement().size(); i++){
        deg += utilities::calcPercentage(attaquant->getPersonnage()->getAttaqueMagique(), 
                                        (dynamic_cast<Arme*>(attaquant->getPersonnage()->getEquipement()[i]))->getDommageMagique());
    }
    if(deg > 100) deg = 100;
    int res = defenseur->getPersonnage()->getResistanceMagique();
    for(unsigned int i = 0; i < defenseur->getPersonnage()->getEquipement().size(); i++){
        res += utilities::calcPercentage(attaquant->getPersonnage()->getResistanceMagique() ,
                                    (dynamic_cast<Arme*>(defenseur->getPersonnage()->getEquipement()[i]))->getDefenseMagique());
    }
    if(res > 100) res = 100;
    int degatReel = deg - utilities::calcPercentage(deg, res);
    int coupCritique = utilities::bernouilli(attaquant->getPersonnage()->getHabilete() / 100.0) * deg * 0.5;
    if(coupCritique > 0) utilities::display("Un coup critique magique est infligé, l'attaque augmente de " + std::to_string(coupCritique) + ".\n");
    return degatReel + coupCritique;
}