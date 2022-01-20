//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_POTION_HPP
#define PROJETLOA_POTION_HPP

#include "Objet.hpp"
#include "ObjectFactory.hpp"
#include <vector>

class Potion: public Objet{
     private:
        Potion(std::string, int, float, std::string);
        friend std::vector<Objet*> initVecteurObjets();
        const float boost;
        const std::string type;
        bool poison;
        Potion* copy() override;
        friend class ObjectFactory;
    public:
        ~Potion() override;
        float getBoost() const;
        std::string getType() const;
        void display() const override;
        std::string toString() const override;
        bool getPoison() const;
        bool isArmeDattaque() const override;
        bool isArmeDeDefense() const override;

};


#endif //PROJETLOA_POTION_HPP
