//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_ARMES_HPP
#define PROJETLOA_ARMES_HPP

#include "Objet.hpp"
#include "ObjectFactory.hpp"

class Jeu;

class Armes: public Objet{
    private:
        const float dommagePhysique;
        const float dommageMagique;
        const float defensePhysique;
        const float defenseMagique;
        Armes(std::string _nom, int _rarete, float _dommagePhysique, float _dommageMagique, float _defensePhysique, float _defenseMagique);
        friend std::vector<Objet*> initVecteurObjets();
        friend class ObjectFactory;
    public:
        float getDommagePhysique() const;
        float getDommageMagique() const;
        float getDefensePhysique() const;
        float getDefenseMagique() const;
};


#endif //PROJETLOA_ARMES_HPP
