//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_ARMES_HPP
#define PROJETLOA_ARMES_HPP

#include "Objet.hpp"

class Armes: public Objet{
    private:
        const float dommagePhysique;
        const float dommageMagique;
        const float defensePhysique;
        const float defenseMagique;
    public:
        Armes(std::string, int, float, float, float, float);
        float getDommagePhysique() const;
        float getDommageMagique() const;
        float getDefensePhysique() const;
        float getDefenseMagique() const;
};


#endif //PROJETLOA_ARMES_HPP
