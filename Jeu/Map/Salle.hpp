//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_SALLE_HPP
#define PROJETLOA_SALLE_HPP

#include <vector>
#include "../../Objets/Objet.hpp"
#include "../Joueur.hpp"

class Salle {

private:
    friend class Chateau;
    const int id;
    std::vector<Joueur*> joueurs;
    std::vector<Objet*> objets;
    Salle* neighbors[4];

public:
    Salle(int);
    int getId() const ;
    int numOfPlayers() const ;
    int numOfObjects() const;
    void addPlayer(Joueur*);

};


#endif //PROJETLOA_SALLE_HPP
