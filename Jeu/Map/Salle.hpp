//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_SALLE_HPP
#define PROJETLOA_SALLE_HPP

#include <vector>
#include "../../Personnages/Personnage.hpp"
#include "../../Objets/Objet.hpp"

class Chateau;

class Salle {

private:
    const int id;
    std::vector<Personnage*> personnages;
    std::vector<Objet*> objets;
    Salle* neighbors[4];
    friend void Chateau::initializeDirections();

public:
    Salle(int);

};


#endif //PROJETLOA_SALLE_HPP
