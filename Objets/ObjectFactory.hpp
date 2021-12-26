#ifndef PROJETLOA_OBJECTFACTORY_HPP
#define PROJETLOA_OBJECTFACTORY_HPP

#include <iostream>
#include <vector>
#include "Objet.hpp"
//class Objet;

class ObjectFactory{
    private:
        const std::vector<Objet*> disponibles;
        const std::vector<Objet*> frequences;
        Objet* pick();
    protected:
    public:
        ObjectFactory(std::vector<Objet*>);
        Objet* produce();

};

#endif