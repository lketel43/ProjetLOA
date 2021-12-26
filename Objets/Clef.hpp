//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_CLEF_HPP
#define PROJETLOA_CLEF_HPP

#include "Objet.hpp"
#include "../Jeu/Joueur.hpp"
#include "../Jeu/Jeu.hpp"

class Clef : public Objet {

private:
    Clef(std::string, int);

public:
    void utiliser(Jeu *, Joueur *, int x, int y);

};


#endif //PROJETLOA_CLEF_HPP
