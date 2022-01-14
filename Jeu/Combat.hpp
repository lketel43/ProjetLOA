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
        static int calculDegatsPhysique(const Joueur*, const Joueur*);
        static int calculDegatsMagique(const Joueur*, const Joueur*);
};

#endif