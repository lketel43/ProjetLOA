#include "JoueurAutomatique.hpp"
#include "../Utilities/utilities.hpp"

using namespace std;

JoueurAutomatique::JoueurAutomatique(std::string _name) : Joueur(_name, true) {}

JoueurAutomatique::~JoueurAutomatique() = default;

void JoueurAutomatique::tourCombat(const Joueur *j) const {
    utilities::display("C'est le tour de l'ennemi.\n");
    if(this->getPersonnage()->getSante() < 30 && this->getPersonnage()->hasPotionBoostSante() != nullptr){
        this->utiliserPotion(this->getPersonnage()->hasPotionBoostSante());
        return;
    }
    if(utilities::random(1, 3) == 3 && this->getPersonnage()->hasPotionPoison() != nullptr){
        utilities::display(this->getName() + " utilise une potion de poison.\n");
        this->utiliserPotionPosion(this->getPersonnage()->hasPotionPoison(), j); //TODO Gérer disparition des potions de l'inventaire
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
    utilities::display("Il vous reste " + to_string(j->getPersonnage()->getSante()) + " points de vie\n\n");
}

void JoueurAutomatique::consulterSacEtEquipement(Jeu *) {

}

void JoueurAutomatique::pickUpObjects(Jeu *) {

}

void JoueurAutomatique::utiliserPotion(Potion* p) const{
    if(!p->getPoison()){
        utilities::display("Le joueur " + this->getName() + " utilise une potion de " + p->getType() + ".\n");
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
        utilities::display("Voici les statistiques de " + this->getName() + " après cette potion:\n");
        utilities::display(this->personnage->getStats());
    }
    int index;
    for(long unsigned int i = 0; i < this->personnage->getSac().size(); i++){
        if(this->personnage->getSac()[i] == p){
            index = i;
        }
    }
    this->personnage->removeFromSac(index);
    delete p;
}

void JoueurAutomatique::utiliserPotionPosion(Potion* p, const Joueur* j) const {
    if(!p->isUtilisable()){
        utilities::display("Cet objet n'est pas utilisable.\n");
        return;
    }
    if (p->getIdType() == IDTYPE_POTION) {
        utilities::display(j->getName() + " choisi d'utiliser une potion de poison affectant la caractéristique " + p->getType() + ".\n");
        if (p->getType() == "sante") {
            utilities::display("La potion inflige " + to_string(-(p->getBoost() / 100) * j->getPersonnage()->getSante()) + " dégâts.\n");
            j->getPersonnage()->subitAttaque(-(p->getBoost() / 100) * j->getPersonnage()->getSante());
        }
        if (p->getType() == "habilete") {
            this->personnage->setHabilete((p->getBoost() / 100) * j->getPersonnage()->getHabilete());
        }
        if (p->getType() == "attaquePhysique") {
            this->personnage->setAttaquePhysique((p->getBoost() / 100) * j->getPersonnage()->getAttaquePhysique());
        }
        if (p->getType() == "attaqueMagique") {
            this->personnage->setAttaqueMagique((p->getBoost() / 100) * j->getPersonnage()->getAttaqueMagique());
        }
        if (p->getType() == "resistancePhysique") {
            this->personnage->setResistancePhysique((p->getBoost() / 100) * j->getPersonnage()->getResistancePhysique());
        }
        if (p->getType() == "resistanceMagique") {
            this->personnage->setResistanceMagique((p->getBoost() / 100) * j->getPersonnage()->getResistanceMagique());
        }
        utilities::display("Voici vos statistiques après cette potion:\n");
        utilities::display(this->personnage->getStats());
    }
    int index;
    for(long unsigned int i = 0; i < this->personnage->getSac().size(); i++){
        if(this->personnage->getSac()[i] == p){
            index = i;
        }
    }
    this->personnage->removeFromSac(index);
    delete p;
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

Joueur* JoueurAutomatique::mort(Jeu *jeu){
    if(this->personnage->getSante() <= 0){
        utilities::display("Le joueur " + nom + " est éliminé du jeu.\n");
        jeu->removeJoueur(this->personnage);
        jeu->getSalle(this->personnage->getPosition())->removePlayer(this->personnage);
        return this;
    }
    return nullptr;
}
void JoueurAutomatique::endTurn(Jeu *jeu) {
    Salle *salle = jeu->getSalle(personnage->getPosition());
    vector<Salle *> neighbors = salle->getNeighbors();

    //choix neighbors.size() veut dire rester sur place
    int choice = utilities::random(0, neighbors.size());

    if (choice != neighbors.size())
        jeu->moveJoueurtoSalle(this, neighbors[choice]);

}
