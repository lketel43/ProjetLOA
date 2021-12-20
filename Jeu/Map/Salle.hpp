//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_SALLE_HPP
#define PROJETLOA_SALLE_HPP

#include <vector>
#include "../../Personnages/Personnage.hpp"
#include "../../Objets/Objet.hpp"

class Salle {

private:
    friend class Chateau;
    const int id;
    std::vector<Personnage*> personnages;
    std::vector<Objet*> objets;
    Salle* neighbors[4];

public:
    Salle(int);

};


#endif //PROJETLOA_SALLE_HPP
