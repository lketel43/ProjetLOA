#include "ObjectFactory.hpp"
#include "../Utilities/Utilities.cpp"

std::vector<Objet*> buildFreq(std::vector<Objet*> v){
    int rareteMax = 0;
    std::vector<Objet*> ret;
    for(int i = 0; i < v.size(); i++){
        if(v.at(i)->getRarete() > rareteMax) rareteMax = v.at(i)->getRarete();
    }
    for(int i = 0; i < v.size(); i++){    
        for(int j = 0; j < rareteMax/v.at(i)->getRarete(); j++){
            ret.push_back(v.at(i));
        }
    }
    return ret;
}

ObjectFactory::ObjectFactory(std::vector<Objet*> v): disponibles(v), frequences(buildFreq(v)){

}

Objet* ObjectFactory::pick(){
    return frequences.at(utilities::random(0, frequences.size() - 1));
}

Objet* ObjectFactory::produce(){
    return this->pick()->copy();
}