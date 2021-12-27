//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Potion.hpp"

using namespace std;

Potion::Potion(std::string _nom, int _rarete, float _boost, std::string _type) : Objet::Objet(_nom, _rarete),
                                                                                 boost(_boost), type(_type) {

}

float Potion::getBoost() const {
    return this->boost;
}

string Potion::toString() const{
     return "Nom: " + nom +"\nRareté:" + to_string(rarete)+
      "\nBoost: "+ type + " " + ((boost > 0) ? "+" : "") + to_string(boost) + "\n";

}
