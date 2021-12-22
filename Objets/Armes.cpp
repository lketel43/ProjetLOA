//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Armes.hpp"

Armes::Armes(std::string _nom, int _rarete, float _dommagePhysiqye, float _dommageMagique, float _defensePhysique, float _defenseMagique): 
    Objet::Objet(_nom, _rarete), 
    dommagePhysique(_dommagePhysiqye), dommageMagique(_dommageMagique),
    defensePhysique(_defensePhysique), defenseMagique(_defenseMagique){

}

float Armes::getDommagePhysique() const{
    return this->dommagePhysique;
}

float Armes::getDommageMagique() const{
    return this->dommageMagique;
}

float Armes::getDefensePhysique() const{
    return this->defensePhysique;
}

float Armes::getDefenseMagique() const{
    return this->defenseMagique;
}