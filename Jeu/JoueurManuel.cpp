#include "JoueurManuel.hpp"
#include "../Utilities/utilities.cpp"


JoueurManuel::JoueurManuel(std::string _name, Personnage *_personnage) : Joueur(_name, _personnage, false) {

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
                    "1.Vous équiper d'une nouvelle arme\n2.Utiliser un objet\n3.Consulter équipement\n4.Retour\n");
            cin >> choice;
            choice = utilities::validateRange(choice, 1, 4);
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
                    }
                    break;
                case 3:
                    return false;
                case 4:
                    return true;
                default:
                    cout << "ERROR IN CHOICE VALIDATION\n";
            }
            utilities::display("Voulez-vous:\n1.Reconsulter sac\n2.Consulter équipement\n3.Retour\n");
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
    if (consulterSac(jeu))
        return;
    else consulterEquipement();
}

