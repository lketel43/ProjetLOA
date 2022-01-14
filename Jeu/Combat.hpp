#ifndef PROJETLOA_COMBAT_HPP
#define PROJETLOA_COMBAT_HPP

#include "Joueur.hpp"
#include <iostream>

class Combat{
    private:
        const Joueur* j1;
        const Joueur* j2;
    public:
        Combat(Joueur*, Joueur*);
        void tour();
        void commencerCombat();
        static int calculDegatsPhysique();
        int calculDegatsMagique();
};

#endif