#include "JoueurManuel.hpp"
#include "../Utilities/Utilities.cpp"


JoueurManuel::JoueurManuel(std::string _name, Personnage* _personnage): Joueur(_name, _personnage, false){

}

void JoueurManuel::tourCombat(Joueur* j){
    utilities::display("C'est votre tour de jouer.\n");
    utilities::display("Voulez-vous :\n");
    utilities::display("1. attaquer\n");
    utilities::display("2. utiliser un objet\n");
    int choice;
    std::cin >> choice;
    choice = utilities::validateRange(choice, 1,2);
    if(choice == 1){
        int degats = Combat::calculDegatsPhysique();
        j->getPersonnage()->subitAttaque(degats);
    }
    if(choice == 2){
        if(this->personnage->getSac().empty()){
            utilities::display("Votre sac est vide, vous attaquez donc votre adversaire\n");
            int degats = Combat::calculDegatsPhysique();
            j->getPersonnage()->subitAttaque(degats);
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
            this->utiliserPotion(this->personnage->getSac()[choice]); // GERER POTION DE POISON
        }
    }
}