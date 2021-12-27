//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Objet.hpp"

using namespace std;

Objet::Objet(string _nom, int _rarete) : nom(_nom), rarete(_rarete) {

}

std::string Objet::getNom() const {
    return this->nom;
}

int Objet::getRarete() const {
    return this->rarete;
}


