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
    ~Salle();
    int getId() const ;
    std::vector<Joueur*> getJoueur() const;
    int numOfPlayers() const ;
    int numOfObjects() const;
    void addPlayer(Joueur*);
    void removePlayer(Joueur*);
    void placeObject(Objet*);
    void display() const;
    void displayEnnemi() const;
    int nbEnnemi();
    bool emptyEnnemi();
    Salle* nord() const;
    Salle* sud() const;
    Salle* est() const;
    Salle * ouest() const;

};

enum directions {
    north, west, east, south
};


#endif //PROJETLOA_SALLE_HPP
