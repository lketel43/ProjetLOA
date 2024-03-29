#include "JoueurManuel.hpp"
#include "../Utilities/utilities.hpp"

using namespace std;

JoueurManuel::JoueurManuel(std::string _name) : Joueur(_name, false) {

}

JoueurManuel::~JoueurManuel() = default;

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
            choice = utilities::validateRange(1, 2);
            return (choice == 2);
        } else {
            utilities::display("Vous êtes équipé de:\n");
            for (long unsigned int i = 0; i < equipement.size(); i++) {
                utilities::display(to_string(i + 1) + "." + equipement[i]->toString());
            }
            utilities::display("Que voulez-vous faire?\n");
            utilities::display(
                    "1.Vous déséquiper d'une de vos armes et la mettre dans votre sac\n2.Jeter une de vos armes\n3.Consulter sac\n4.Retour\n");
            choice = utilities::validateRange(1, 4);
            if (choice > 2)
                return (choice == 4);
            switch (choice) {
                case 1:
                    if (personnage->isSacFull()) {
                        utilities::display("Votre sac est actuellement plein. Veuillez le vider avant d'y rajouter des objets.\n");

                    } else {
                        utilities::display("Choisissez l'arme que vous souhaitez mettre dans votre sac.\n");
                        for (long unsigned int i = 0; i < equipement.size(); i++) {
                            utilities::display(to_string(i + 1) + "." + equipement[i]->getNom() + "\n");
                        }

                        choice = utilities::validateRange(1, equipement.size());
                        utilities::display(
                                "Vous avez placé " + equipement[choice - 1]->getNom() + " dans votre sac.\n");
                        desequiper(choice - 1);

                    }
                    break;
                case 2:
                    utilities::display("Choisissez l'arme que vous souhaitez jeter.\n");
                    for (long unsigned int i = 0; i < equipement.size(); i++) {
                        utilities::display(to_string(i + 1) + "." + equipement[i]->getNom() + "\n");
                    }
                    choice = utilities::validateRange(1, equipement.size());
                    utilities::display("Vous avez jeter: " + equipement[choice - 1]->getNom() + "\n");
                    jeu->placerDansSalle(this->personnage->getPosition(), equipement[choice - 1]);
                    personnage->removeFromEquipement(choice - 1);
                    break;
                default:
                    cout << "ERROR IN CHOICE VALIDATION AND/OR PROCESSING \n";
            }
            utilities::display(
                    "Voulez-vous:\n1.Continuer à consulter votre équipement\n2.Consulter votre sac\n3.Retour\n");

            choice = utilities::validateRange(1, 3);
            if (choice == 3)
                return true;
            continueLooping = (choice == 1);
        }

    } while (continueLooping);

    return continueLooping;

}


//return true if we need to exit the bigger function
bool JoueurManuel::consulterSac(Jeu *jeu) {
    bool continueLooping = false;
    vector<Objet *> sac;
    unsigned int choice;
    vector<pair<Objet *, long unsigned int> > objetsEquippables;
    vector<pair<Objet *, long unsigned int> > objetsUtilisables;
    do {
        sac = personnage->getSac();
        if (sac.empty()) {
            utilities::display("Votre sac est vide.\n");
            utilities::display("Essayez de le remplir avec les objets dans la salle.\n");
            utilities::display("Voulez-vous revenir au menu des choix possible, ou consulter votre équipement?\n");
            utilities::display("1.Consulter équipement\n2.Retour au menu\n");

            choice = utilities::validateRange(1, 2);
            return (choice == 2);

        } else {

            utilities::display("Votre sac contient: \n");

            for (long unsigned int i = 0; i < sac.size(); i++) {
                utilities::display(to_string(i + 1) + "." + sac[i]->toString());
            }

            utilities::display(
                    "Voulez-vous: \n");
            utilities::display(
                    "1.Vous équiper d'une arme dans votre sac\n2.Utiliser un objet\n3.Consulter équipement\n4.Vous débarasser d'un objet dans votre sac\n5.Retour\n");

            choice = utilities::validateRange(1, 5);
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
                            utilities::display(to_string(i + 1) + "." + objetsEquippables[i].first->toString() + "\n");
                        //then choose arm
                        utilities::display("Que choisissez-vous?\n");

                        choice = utilities::validateRange(1, objetsEquippables.size());
                        //then remove arm from bag
                        utilities::display(
                                "Vous vous êtes équipé de: " + objetsEquippables[choice - 1].first->getNom() + "\n");
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

                        choice = utilities::validateRange(1, objetsUtilisables.size());
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
                    choice = utilities::validateRange(1, sac.size() + 1);
                    if (choice == sac.size() + 1)
                        break;
                    else {
                        jeu->placerDansSalle(this->personnage->getPosition(), sac[choice - 1]);
                        personnage->removeFromSac((choice - 1));
                    }

                case 5:
                    return true;
                default:
                    cout << "ERROR IN CHOICE VALIDATION\n";
            }
            utilities::display(
                    "Voulez-vous:\n1.Continuer à consulter votre sac\n2.Consulter votre équipement\n3.Retour\n");

            choice = utilities::validateRange(1, 3);
            if (choice == 3)
                return true;
            continueLooping = (choice == 1);
        }

    } while (continueLooping);

    //unnecessary
    return continueLooping;

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
    Salle *salle = jeu->getSalle(this->personnage->getPosition());
    int choice;
    bool continueLooping;
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

            choice = utilities::validateRange(1, salle->numOfObjects());
            ramasser(salle->removeObject(choice - 1));
        }
        utilities::display("Maintenant, voulez-vous: \n1.Ramasser un autre objet\n2.Retour\n");

        choice = utilities::validateRange(1, 2);
        continueLooping = (choice == 1);
    } while (continueLooping);


}

void JoueurManuel::utiliserPotion(Potion *p) const {
    if (!p->isUtilisable()) {
        utilities::display("Cet objet n'est pas utilisable.\n");
        return;
    }
    if (p->getIdType() == IDTYPE_POTION) {
        utilities::display("Vous avez choisi d'utiliser une potion de type " + p->getType() + ".\n");
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
    for (long unsigned int i = 0; i < this->personnage->getSac().size(); i++) {
        if (this->personnage->getSac()[i] == p) {
            index = i;
        }
    }
    this->personnage->removeFromSac(index);
    delete p;
}

void JoueurManuel::utiliserPotionPosion(Potion *p, const Joueur *j) const {
    if (!p->isUtilisable()) {
        utilities::display("Cet objet n'est pas utilisable.\n");
        return;
    }
    if (p->getIdType() == IDTYPE_POTION) {
        utilities::display(
                "Vous avez choisi d'utiliser une potion de poison affectant la caractéristique " + p->getType() +
                ".\n");
        if (p->getType() == "sante") {
            utilities::display(
                    "La potion inflige " + to_string(-(p->getBoost() / 100) * j->getPersonnage()->getSante()) +
                    " dégâts.\n");
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
            this->personnage->setResistancePhysique(
                    (p->getBoost() / 100) * j->getPersonnage()->getResistancePhysique());
        }
        if (p->getType() == "resistanceMagique") {
            this->personnage->setResistanceMagique((p->getBoost() / 100) * j->getPersonnage()->getResistanceMagique());
        }
        utilities::display("Voici les statistiques de l'ennemi après cette potion:\n");
        utilities::display(j->getPersonnage()->getStats());
    }
    int index;
    for (long unsigned int i = 0; i < this->personnage->getSac().size(); i++) {
        if (this->personnage->getSac()[i] == p) {
            index = i;
        }
    }
    this->personnage->removeFromSac(index);
    delete p;
}


void JoueurManuel::tourCombat(const Joueur *j) const {
    utilities::display("Voulez-vous :\n");
    utilities::display("1. attaquer\n");
    utilities::display("2. utiliser un objet\n");
    int choice;

    choice = utilities::validateRange(1, 2);
    if (choice == 1) {
        int degatsP = Combat::calculDegatsPhysique(this, j);
        int degatsM = Combat::calculDegatsMagique(this, j);
        j->getPersonnage()->subitAttaque(degatsP + degatsM);
        utilities::display(
                "Vous infligez " + std::to_string(degatsP + degatsM) + " points de dégâts à votre adversaire\n");
        utilities::display("Il lui reste " + std::to_string(j->getPersonnage()->getSante()) + " points de sante\n");
    }
    if (choice == 2) {
        if (this->personnage->getSac().empty()) {
            utilities::display("Votre sac est vide, vous attaquez donc votre adversaire\n");
            int degatsP = Combat::calculDegatsPhysique(this, j);
            int degatsM = Combat::calculDegatsMagique(this, j);
            j->getPersonnage()->subitAttaque(degatsP + degatsM);
            utilities::display(
                    "Vous infligez " + std::to_string(degatsP + degatsM) + " points de dégâts à votre adversaire\n");
            utilities::display("Il lui reste " + std::to_string(j->getPersonnage()->getSante()) + " points de sante\n");
        } else {
            vector<pair<Objet *, long unsigned int> > objetsUtilisables;
            for (long unsigned int i = 0; i < this->personnage->getSac().size(); i++) {
                if (this->personnage->getSac()[i]->isUtilisable()) {
                    pair<Objet *, long unsigned int> pair2(this->personnage->getSac()[i], i);
                    objetsUtilisables.push_back(pair2);
                }
            }
            if (objetsUtilisables.size() == 0) {
                utilities::display("Aucun objet de votre sac n'est utilisable, vous attaquez donc votre ennemi.\n");
                int degatsP = Combat::calculDegatsPhysique(this, j);
                int degatsM = Combat::calculDegatsMagique(this, j);
                j->getPersonnage()->subitAttaque(degatsP + degatsM);
                utilities::display("Vous infligez " + std::to_string(degatsP + degatsM) +
                                   " points de dégâts à votre adversaire\n");
                utilities::display(
                        "Il lui reste " + std::to_string(j->getPersonnage()->getSante()) + " points de sante\n");
            } else {
                utilities::display(
                        "Votre sac contient les objets utilisables suivants, lequel voulez-vous utiliser ?\n");
                for (unsigned int i = 1; i < objetsUtilisables.size() + 1; i++) {
                    utilities::display(std::to_string(i) + ". " + objetsUtilisables[i - 1].first->getNom() + "\n");
                }

                choice = utilities::validateRange(1, this->personnage->getSac().size());
                choice -= 1;
                utilities::display("Vous avez choisi d'utiliser l'objet " +
                                   this->personnage->getSac()[objetsUtilisables[choice].second]->getNom() + "\n");
                if (!(dynamic_cast<Potion *>(this->personnage->getSac()[choice]))->getPoison()) { //Si ce n'est pas une potion de poison
                    this->utiliserPotion(
                            dynamic_cast<Potion *>(this->personnage->getSac()[objetsUtilisables[choice].second]));
                } else {
                    this->utiliserPotionPosion(
                            (dynamic_cast<Potion *>(this->personnage->getSac()[objetsUtilisables[choice].second])), j);
                }
            }
        }
    }
    utilities::display("C'est la fin de votre tour\n\n");
}

int JoueurManuel::choosePersonnage(std::vector<std::pair<Personnage *, int>> personnagesDisponiblesEtFrequences) {
    int choice;
    string name;
    utilities::display("À vous Joueur " + nom + " de choisir votre personnage." + "\n" +
                       "Choisissez un nombre entre 1 et " +
                       to_string(personnagesDisponiblesEtFrequences.size()) + "." + "\n"
                       + "Attention! Ce choix est définitif." + "\n");

    choice = utilities::validateRange(1, personnagesDisponiblesEtFrequences.size());
    utilities::display("Bon choix. \n");
    utilities::display("Vous êtes digne d'un vrai prénom également. Quel est votre prénom?\n");
    cin >> name;
    this->nom = name;
    return choice;
}

Joueur *JoueurManuel::mort(Jeu *jeu) {
    if (this->personnage->getSante() <= 0) {
        utilities::display(nom + " est éliminé du jeu.\n");
        jeu->removeJoueur(this->personnage);
        jeu->getSalle(this->personnage->getPosition())->removePlayer(this->personnage);
        this->personnage = nullptr;
        return this;
    }
    return nullptr;
}

void JoueurManuel::endTurn(Jeu *jeu) {
    Salle *salle = jeu->getSalle(this->personnage->getPosition());
    vector<Salle *> neighbors = salle->getNeighbors();
    int choice;
    utilities::display("Vous avez decidé de finir votre tour.\n");
    utilities::display("Avant de faire ceci, voulez-vous changer de salle?\n");
    utilities::display("1. Oui \n2. Non\n");


    choice = utilities::validateRange(1, 2);
    if (choice == 1) {
        utilities::display("Vous avez choisi de changer de salle avant la fin de votre tour.\n");
        utilities::display("Voici la carte du chateau, votre position est marquée par un 'x'\n");
        jeu->displayMap(this);

        utilities::display("Vous avez donc le choix d'aller dans les salles suivantes: \n");
        for (long unsigned int i = 0; i < neighbors.size(); i++) {
            utilities::display(to_string(i + 1) + ". Salle " + to_string(neighbors[i]->getId()) + "\n");
        }
        utilities::display("Quelle salle choisissez-vous?\n");
        choice = utilities::validateRange(1, neighbors.size());
        jeu->moveJoueurtoSalle(this, neighbors[choice - 1]);
        utilities::display("Vous êtes maintenant dans la salle " + to_string(neighbors[choice - 1]->getId()) + "\n");

    }
    utilities::display("Fin de tour pour le Joueur " + this->getName() + "\n");
}