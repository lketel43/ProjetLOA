//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_PERSONNAGE_HPP
#define PROJETLOA_PERSONNAGE_HPP

#include "../Objets/Objet.hpp"


class Personnage {

private:

    std::string nom;
    int sante;
    int habilite;
    Objet* sac[4];


};


#endif //PROJETLOA_PERSONNAGE_HPP
