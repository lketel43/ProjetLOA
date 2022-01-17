#include "JoueurAutomatique.hpp"
#include "../Utilities/Utilities.cpp"

JoueurAutomatique::JoueurAutomatique(std::string _name, Personnage * _personnage): Joueur(_name, _personnage, true) {}

void JoueurAutomatique::tourCombat(const Joueur* j) const{
    utilities::display("C'est le tour de " + this->nom + " de joueur\n");
    if(this->getPersonnage()->getSante() < 30 && this->getPersonnage()->hasPotionBoostSante() != nullptr){
        this->utiliserPotion(this->getPersonnage()->hasPotionBoostSante());
        return;
    }
    if(utilities::random(1, 3) == 3 && this->getPersonnage()->hasPotionPoison() != nullptr){
        utilities::display(this->getName() + " utilise une potion de poison.\n");
        j->getPersonnage()->subitAttaque(this->getPersonnage()->hasPotionPoison()->getBoost()); //TODO Gérer disparition des potions de l'inventaire
        return;
    }
    if(utilities::random(1, 3) == 3 && this->getPersonnage()->hasPotionBoost() != nullptr){
        this->utiliserPotion(this->getPersonnage()->hasPotionBoost());
        return;
    }
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

//TODO Gérer disparition des potions de l'inventaire
void JoueurAutomatique::utiliserPotion(Potion* p) const{
    if(!p->getPoison()){
        utilities::display("Le joueur" + this->getName() + " utilise une potion de " + p->getType() + ".\n");
        if (p->getType() == "sante") {
            this->personnage->setSante(p->getBoost());
        }
        if (p->getType() == "habilete") {
            this->personnage->setHabilete(p->getBoost());
        }
        if (p->getType() == "attaquePhysique") {
            this->personnage->setAttaquePhysique(p->getBoost());
        }
        if (p->getType() == "attaqueMagique") {
            this->personnage->setAttaqueMagique(p->getBoost());
        }
        if (p->getType() == "resistancePhysique") {
            this->personnage->setResistancePhysique(p->getBoost());
        }
        if (p->getType() == "resistanceMagique") {
            this->personnage->setResistanceMagique(p->getBoost());
        }
        utilities::display("Voici les statistiques" + this->getName() + "après cette potion:\n");
        utilities::display(this->personnage->getStats());
    }
}


