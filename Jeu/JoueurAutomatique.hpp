#ifndef PROJETLOA_JOUEUR_AUTOMATIQUE_HPP
#define PROJETLOA_JOUEUR_AUTOMATIQUE_HPP

#include "Joueur.hpp"

class JoueurAutomatique : public Joueur{
public:
    JoueurAutomatique(std::string, Personnage*);
    //TODO: IMPLEMENT BELOW FUNCTION
    void consulterSacEtEquipement(Jeu*) override;
    //TODO: IMPLEMENT BELOW FUNCTION
    void pickUpObjects(Jeu*) override;

};

#endif 