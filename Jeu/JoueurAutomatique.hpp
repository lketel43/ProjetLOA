#ifndef PROJETLOA_JOUEUR_AUTOMATIQUE_HPP
#define PROJETLOA_JOUEUR_AUTOMATIQUE_HPP

#include "Joueur.hpp"
#include "Combat.hpp"

class JoueurAutomatique : public Joueur{
public:
    JoueurAutomatique(std::string, Personnage*);
    void tourCombat(const Joueur*) const override;
};

#endif 