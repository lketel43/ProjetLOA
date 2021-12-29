//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Objet.hpp"

Objet::Objet(std::string _nom, int _rarete, bool _equipable, bool _utilisable, int _idType): nom(_nom), rarete(_rarete), 
equipable(_equipable), utilisable(_utilisable), idType(_idType){

}

std::string Objet::getNom() const{
    return this->nom;
}

int Objet::getRarete() const{
    return this->rarete;
}

Objet* Objet::copy(){
    return new Objet(this->nom, this->rarete, this->equipable, this->utilisable, this->idType);
}

bool Objet::isEquipable(){
    return this->equipable;
}

bool Objet::isUtilisable(){
    return this->utilisable;
}

int Objet::getIdType() const{
    return this->idType;
}