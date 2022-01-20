#ifndef PROJETLOA_OBJECTFACTORY_HPP
#define PROJETLOA_OBJECTFACTORY_HPP

#include <iostream>
#include <vector>
#include "Objet.hpp"


class ObjectFactory{
    private:
        const std::vector<Objet*> disponibles;
        const std::vector<Objet*> frequences;
        Objet* pick();

    public:
        ObjectFactory(std::vector<Objet*>);
        ~ObjectFactory();
        Objet* produce();
        Objet* produceArmeBasique();
        Objet* producePotion();

};

#endif