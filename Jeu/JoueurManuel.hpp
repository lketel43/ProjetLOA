#ifndef PROJETLOA_JOUEUR_MANUEL_HPP
#define PROJETLOA_JOUEUR_MANUEL_HPP

#include "Joueur.hpp"
#include "Combat.hpp"

class JoueurManuel : public Joueur {

public:
    JoueurManuel(std::string, Personnage*);
    void tourCombat(Joueur*);

};

#endif 