//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_POTION_HPP
#define PROJETLOA_POTION_HPP

#include "Objet.hpp"
#include "ObjectFactory.hpp"
#include <vector>

class Potion: public Objet{
    public:
        float getBoost() const;
        std::string getType() const;
    private:
        Potion(std::string, int, float, std::string);
        friend std::vector<Objet*> initVecteurObjets();
        const float boost;
        const std::string type;
        friend class ObjectFactory;
};


#endif //PROJETLOA_POTION_HPP
