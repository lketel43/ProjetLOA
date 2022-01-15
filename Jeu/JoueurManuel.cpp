#include "JoueurManuel.hpp"
#include "../Utilities/Utilities.cpp"
#include "../Objets/Potion.hpp"


JoueurManuel::JoueurManuel(std::string _name, Personnage* _personnage): Joueur(_name, _personnage, false){

}

void JoueurManuel::tourCombat(const Joueur* j) const{
    utilities::display("C'est votre tour de jouer.\n");
    utilities::display("Voulez-vous :\n");
    utilities::display("1. attaquer\n");
    utilities::display("2. utiliser un objet\n");
    int choice;
    std::cin >> choice;
    choice = utilities::validateRange(choice, 1,2);
    if(choice == 1){
        int degatsP = Combat::calculDegatsPhysique(this, j);
        int degatsM = Combat::calculDegatsMagique(this, j);
        j->getPersonnage()->subitAttaque(degatsP + degatsM);
        utilities::display("Vous infligez " + std::to_string(degatsP + degatsM) + " points de dégâts à votre adversaire\n");
        utilities::display("Il lui reste " + std::to_string(j->getPersonnage()->getSante()) + " points de sante\n");
    }
    if(choice == 2){
        if(this->personnage->getSac().empty()){
            utilities::display("Votre sac est vide, vous attaquez donc votre adversaire\n");
            int degatsP = Combat::calculDegatsPhysique(this, j);
            int degatsM = Combat::calculDegatsMagique(this, j);
            j->getPersonnage()->subitAttaque(degatsP + degatsM);
            utilities::display("Vous infligez " + std::to_string(degatsP + degatsM) + " points de dégâts à votre adversaire\n");
            utilities::display("Il lui reste " + std::to_string(j->getPersonnage()->getSante()) + " points de sante\n");
        }
        else{
            utilities::display("Votre sac contient les objets suivants, lequel voulez-vous utiliser ?\n");
            for(unsigned int i = 0; i < this->personnage->getSac().size(); i++){
                utilities::display(std::to_string(i) + ". " + this->personnage->getSac()[i]->getNom());
            }
            std::cin >> choice;
            do{
                choice = utilities::validateRange(choice, 0, this->personnage->getSac().size() - 1);
                if(this->personnage->getSac()[choice]->getIdType() != 1){
                    utilities::display("Vous ne pouvez pas utiliser cet objet pendant le combat");
                }
            }
            while(this->personnage->getSac()[choice]->getIdType() != 1);
            utilities::display("Vous avez choisi d'utiliser l'objet " + this->personnage->getSac()[choice]->getNom());
            if(!(dynamic_cast<Potion*>(this->personnage->getSac()[choice]))->getPoison()){ //Si ce n'est pas une potion de poison
                this->utiliserPotion(dynamic_cast<Potion*>(this->personnage->getSac()[choice]));
            }
            else{
                j->getPersonnage()->subitAttaque((dynamic_cast<Potion*>(this->personnage->getSac()[choice]))->getBoost());
            }
        }
    }
    utilities::display("C'est la fin de votre tour\n");
}