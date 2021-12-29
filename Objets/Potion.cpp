//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Potion.hpp" 

Potion::Potion(std::string _nom, int _rarete, float _boost, std::string _type): Objet::Objet(_nom, _rarete, false, true, 1), boost(_boost), type(_type){

}

std::string Potion::getType() const{
    return this->type;
}

float Potion::getBoost() const{
    return this->boost;
}
