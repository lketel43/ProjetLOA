#ifndef PROJETLOA_JOUEUR_AUTOMATIQUE_HPP
#define PROJETLOA_JOUEUR_AUTOMATIQUE_HPP

#include "Joueur.hpp"

class JoueurAutomatique : public Joueur{
public:
    JoueurAutomatique(std::string, Personnage*);
    void consulterSacEtEquipement(Jeu*) override;

};

#endif 