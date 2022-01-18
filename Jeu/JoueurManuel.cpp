#include "JoueurManuel.hpp"
#include "../Utilities/Utilities.cpp"


JoueurManuel::JoueurManuel(std::string _name, Personnage *_personnage) : Joueur(_name, _personnage, false) {

}

//return true if we need to exit the bigger function
bool JoueurManuel::consulterEquipement(Jeu *jeu) {
    vector<Objet *> equipement;
    int choice;
    bool continueLooping = false;

    do {
        equipement = personnage->getEquipement();
        if (equipement.empty()) {
            utilities::display("Vous n'avez aucun équipement.\n");
            utilities::display("Essayez de vous équiper d'une des armes dans votre sac.\n");
            utilities::display("Voulez-vous revenir au menu des choix possible, ou consulter votre sac?\n");
            utilities::display("1.Consulter sac\n2.Retour au menu\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 2);
            return (choice == 2);
        } else {
            utilities::display("Vous êtes équipé de:\n");
            for (long unsigned int i = 0; i < equipement.size(); i++) {
                utilities::display(to_string(i + 1) + "." + equipement[i]->toString());
            }
            utilities::display("Que voulez-vous faire?\n");
            utilities::display(
                    "1.Vous déséquiper d'une de vos armes et la mettre dans votre sac\n2.Jeter une de vos armes\n3.Consulter sac\n4.Retour\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 4);
            if (choice > 2)
                return (choice == 4);
            switch (choice) {
                case 1:
                    utilities::display("Choisissez l'arme que vous souhaitez mettre dans votre sac.\n");
                    for (long unsigned int i = 0; i < equipement.size(); i++) {
                        utilities::display(to_string(i + 1) + "." + equipement[i]->getNom());
                    }
                    cin >> choice;
                    choice = utilities::validateRange(choice, 1, equipement.size());
                    desequiper(choice - 1);
                    break;
                case 2:
                    utilities::display("Choisissez l'arme que vous souhaitez jeter.\n");
                    cin >> choice;
                    choice = utilities::validateRange(choice, 1, equipement.size());
                    jeu->placerDansSalle(this->position, equipement[choice - 1]);
                    equipement.erase(equipement.begin() + choice - 1);
                    break;
                default:
                    cout << "ERROR IN CHOICE VALIDATION AND/OR PROCESSING \n";
            }
            utilities::display(
                    "Voulez-vous:\n1.Continuer à consulter votre équipement\n2.Consulter votresac\n3.Retour\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 3);
            if (choice == 3)
                return true;
            continueLooping = (choice == 1);
        }

    } while (continueLooping);

}


//return true if we need to exit the bigger function
bool JoueurManuel::consulterSac(Jeu *jeu) {
    bool continueLooping = false;
    vector<Objet *> sac;
    int choice;
    vector<pair<Objet *, long unsigned int> > objetsEquippables;
    vector<pair<Objet *, long unsigned int> > objetsUtilisables;
    do {
        sac = personnage->getSac();
        if (sac.empty()) {
            utilities::display("Votre sac est vide.\n");
            utilities::display("Essayez de le remplir avec les objets dans la salle.\n");
            utilities::display("Voulez-vous revenir au menu des choix possible, ou consulter votre équipement?\n");
            utilities::display("1.Consulter équipement\n2.Retour au menu\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 2);
            return (choice == 2);

        } else {

            utilities::display("Votre sac contient: \n");

            for (long unsigned int i = 0; i < sac.size(); i++) {
                utilities::display(to_string(i + 1) + "." + sac[i]->toString());
            }

            utilities::display(
                    "Voulez-vous: \n");
            utilities::display(
                    "1.Vous équiper d'une nouvelle arme\n2.Utiliser un objet\n3.Consulter équipement\n4.Vous débarasser d'un objet dans votre sac\n5.Retour\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 5);
            switch (choice) {
                case 1:
                    objetsEquippables.clear();
                    //Need to check they have one empty hand
                    if (personnage->isEquipementFull()) {
                        utilities::display("Vos deux mains sont actuellement équippées.\n"
                                           "Veuillez consulter d'abord votre équipement pour vous libérer une main\n");
                        break;
                    }
                    //choix entre toutes les armes equipables
                    for (long unsigned int i = 0; i < sac.size(); i++) {
                        if (sac[i]->isEquipable()) {
                            pair<Objet *, long unsigned int> pair2(sac[i], i);
                            objetsEquippables.push_back(pair2);
                        }
                    }
                    //then show the arms they can use
                    if (objetsEquippables.empty()) {
                        utilities::display("Vous n'avez aucun objet équipable dans votre sac.\n");
                        break;
                    } else {

                        utilities::display("Voici les objets dans votre sac dont vous pouvez vous équipper:\n");
                        for (long unsigned int i = 0; i < objetsEquippables.size(); i++)
                            utilities::display(to_string(i + 1) + "." + objetsEquippables[i].first->toString());
                        //then choose arm
                        utilities::display("Que choisissez-vous?\n");
                        cin >> choice;
                        choice = utilities::validateRange(choice, 1, objetsEquippables.size());
                        //then remove arm from bag
                        utilities::display("Vous vous êtes équipé de: "+ objetsEquippables[choice - 1].first->getNom() + "\n");
                        personnage->removeFromSac(objetsEquippables[choice - 1].second);
                        // then equip arm
                        personnage->addToEquipement(objetsEquippables[choice - 1].first);
                    }
                    break;
                case 2:
                    objetsUtilisables.clear();
                    //Need to show usable objects
                    //TODO: can be ameliorated
                    //TODO: can make function that creates objetUtilisables like in TPN3
                    for (long unsigned int i = 0; i < sac.size(); i++) {
                        if (sac[i]->isUtilisable()) {
                            pair<Objet *, long unsigned int> pair2(sac[i], i);
                            objetsUtilisables.push_back(pair2);
                        }
                    }
                    if (objetsUtilisables.empty()) {
                        utilities::display("Vous n'avez aucun objet que vous pouvez utiliser.\n");
                        break;
                    } else {
                        utilities::display("Voici les objets dans votre sac que vous pouvez utiliser:\n");
                        for (long unsigned int i = 0; i < objetsUtilisables.size(); i++)
                            utilities::display(to_string(i + 1) + "." + objetsUtilisables[i].first->toString());
                        //then choose object
                        utilities::display("Que choisissez-vous?\n");
                        cin >> choice;
                        choice = utilities::validateRange(choice, 1, objetsUtilisables.size());
                        switch (objetsUtilisables[choice - 1].first->getIdType()) {
                            case IDTYPE_ARME:
                                cout << "ERROR OBJET NON UTILISABLE\n";
                                break;
                            case IDTYPE_CLEF:
                                utiliserClef(dynamic_cast<Clef *>(objetsUtilisables[choice - 1].first), jeu);
                                break;
                            case IDTYPE_POTION:
                                utiliserPotion(dynamic_cast<Potion *>(objetsUtilisables[choice - 1].first));
                                break;
                        }
                        //remove item from sac
                        personnage->removeFromSac(objetsUtilisables[choice - 1].second);
                    }
                    break;
                case 3:
                    return false;
                case 4:
                    utilities::display("Vous avez choisi de vous débarrasser d'un de vos objets.\n");
                    utilities::display("Lequel des objets choisissez-vous?\n");
                    for (long unsigned int i = 0; i < sac.size(); i++) {
                        utilities::display(to_string(i + 1) + "." + sac[i]->getNom() + "\n");
                    }
                    utilities::display(
                            to_string(sac.size() + 1) + ".Je ne veux plus me débarrasser d'un de mes objets.\n");
                    cin >> choice;
                    choice = utilities::validateRange(choice, 1, sac.size() + 1);
                    if (choice == sac.size() + 1)
                        break;
                    else {
                        jeu->placerDansSalle(this->position, sac[choice - 1]);
                        personnage->removeFromSac((choice - 1));
                    }

                case 5:
                    return true;
                default:
                    cout << "ERROR IN CHOICE VALIDATION\n";
            }
            utilities::display(
                    "Voulez-vous:\n1.Continuer à consulter votre sac\n2.Consulter votre équipement\n3.Retour\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 3);
            if (choice == 3)
                return true;
            continueLooping = (choice == 1);
        }

    } while (continueLooping);

}


void JoueurManuel::consulterSacEtEquipement(Jeu *jeu) {
    utilities::display("Vous avez choisi de consulter votre sac et votre équipement.\n");
    //Si le joueur a choisi de retourner au menu completement
    do {
        if (consulterSac(jeu))
            return;
    } while (!consulterEquipement(jeu));


}

void JoueurManuel::pickUpObjects(Jeu *jeu) {
    Salle *salle = jeu->getSalle(position);
    int choice;
    bool continueLooping = false;
    do {
        if (personnage->isSacFull()) {
            utilities::display("Votre sac est rempli. Veuillez le vider avant de ramasser des objets.\n");
            return;
        } else {
            if (salle->hasNoObjects()) {
                utilities::display("La salle ne contient pas d'objets.\n");
                return;
            }
            utilities::display("Voici les objets dans la salle:\n");
            salle->displayObjects();
            utilities::display("Lequel parmi ceux-ci voulez-vous ramasser?\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, salle->numOfObjects());
            ramasser(salle->removeObject(choice - 1));
        }
        utilities::display("Maintenant, voulez-vous: \n1.Ramasser un autre objet\n2.Retour\n");
        cin >> choice;
        choice = utilities::validateRange(choice, 1, 2);
        continueLooping = (choice == 1);
    } while (continueLooping);


}

void JoueurManuel::utiliserPotion(Potion *p) const{
    if(!p->isUtilisable()){
        utilities::display("Cet objet n'est pas utilisable.\n");
        return;
    }
    if (p->getIdType() == IDTYPE_POTION) {
        utilities::display("Vous avez choisi d'utiliser une potion de type" + p->getType() + ".\n");
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

void JoueurManuel::utiliserPotionPosion(Potion* p, const Joueur* j) const{
    if(!p->isUtilisable()){
        utilities::display("Cet objet n'est pas utilisable.\n");
        return;
    }
    if (p->getIdType() == IDTYPE_POTION) {
        utilities::display("Vous avez choisi d'utiliser une potion de poison affectant la caractéristique " + p->getType() + ".\n");
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
        utilities::display("Voici les statistiques de l'ennemi après cette potion:\n");
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
                this->utiliserPotionPosion((dynamic_cast<Potion*>(this->personnage->getSac()[choice])), j);
            }
        }
    }
    utilities::display("C'est la fin de votre tour\n");
}

