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
    const std::string description;
    Clef(std::string , int, std::string );
    Clef* copy() override;


public:
    void utiliser(Jeu *, Joueur *, int x, int y);
    void display() const override;
    std::string toString() const override;


};


#endif //PROJETLOA_CLEF_HPP
