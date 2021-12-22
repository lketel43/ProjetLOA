//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Potion.hpp" 

Potion::Potion(std::string _nom, int _rarete, float _boost, std::string _type): Objet::Objet(_nom, _rarete), boost(_boost), type(_type){

}

float Potion::getBoost() const{
    return this->boost;
}
