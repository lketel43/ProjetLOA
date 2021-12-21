//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_JOUEUR_HPP
#define PROJETLOA_JOUEUR_HPP

#include "../Personnages/Personnage.hpp"
#include <utility>

class Joueur {
private:
    Personnage * personnage;
    const bool automatise;
    const std::string nom;
    std::pair<int, int> position;
    int score;

public:
    Joueur(std::string, Personnage*, bool);
    void setPosition(const int&, const int&);



};


#endif //PROJETLOA_JOUEUR_HPP
