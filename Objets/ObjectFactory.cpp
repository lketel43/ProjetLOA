#include "ObjectFactory.hpp"
#include "../Utilities/utilities.hpp"

std::vector<Objet *> buildFreq(std::vector<Objet *> v) {
    int rareteMax = 0;
    std::vector<Objet *> ret;
    for (unsigned int i = 0; i < v.size(); i++) {
        if (v.at(i)->getRarete() > rareteMax) rareteMax = v.at(i)->getRarete();
    }
    for (unsigned int i = 0; i < v.size(); i++) {
        for (int j = 0; j < rareteMax / v.at(i)->getRarete(); j++) {
            ret.push_back(v.at(i));
        }
    }
    return ret;
}

ObjectFactory::ObjectFactory(std::vector<Objet *> v) : disponibles(v), frequences(buildFreq(v)) {

}

Objet *ObjectFactory::pick() {
    return frequences.at(utilities::random(0, frequences.size() - 1));
}

Objet *ObjectFactory::produce() {
    return this->pick()->copy();
}

ObjectFactory::~ObjectFactory() {
    for (long unsigned int i = 0; i < disponibles.size(); i++)
        delete disponibles[i];

    //Pas besoin de supprimer les autre poiteurs
}

Objet *ObjectFactory::produceArmeBasique() {
    Objet *objet;
    while (true) {
        objet = produce();
        if (objet->equipable && objet->getRarete() <= 5)
            return objet;
    }
}

Objet* ObjectFactory::producePotion() {
    Objet *objet;
    while (true) {
        objet = produce();
        if (objet->getIdType() == IDTYPE_POTION)
            return objet;
    }
}
