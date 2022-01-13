//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_ARME_HPP
#define PROJETLOA_ARME_HPP

#include "Objet.hpp"
#include "ObjectFactory.hpp"

class Jeu;

class Arme: public Objet{
    private:
        const float dommagePhysique;
        const float dommageMagique;
        const float defensePhysique;
        const float defenseMagique;
        Arme(std::string _nom, int _rarete, float _dommagePhysique, float _dommageMagique, float _defensePhysique, float _defenseMagique);
        friend std::vector<Objet*> initVecteurObjets();
        friend class ObjectFactory;
        Arme* copy() override;
    public:
        float getDommagePhysique() const;
        float getDommageMagique() const;
        float getDefensePhysique() const;
        float getDefenseMagique() const;
        void display() const override;
        std::string toString() const override;
};


#endif //PROJETLOA_ARME_HPP
