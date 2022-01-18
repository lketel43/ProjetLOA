//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_SALLE_HPP
#define PROJETLOA_SALLE_HPP

#include <vector>
#include "../../Objets/Objet.hpp"

class Joueur;

class Salle {

private:
    friend class Chateau;
    const int id;
    std::vector<Joueur*> joueurs;
    std::vector<Objet*> objets;
    std::vector<Salle*> neighbors;

public:
    Salle(int);
    ~Salle();
    const int getId() const ;
    std::vector<Joueur*> getJoueur() const;
    int numOfPlayers() const ;
    int numOfObjects() const;
    void addPlayer(Joueur*);
    void removePlayer(Joueur*);
    void placeObject(Objet*);
    Objet* removeObject(int);
    void displayObjects() const;
    bool hasNoObjects() const;
    bool hasNoOtherPlayers() const;
    void display() const;
    void displayEnnemi() const;
    int nbEnnemi() const;
    std::vector<Salle*> getNeighbors() const;

};

enum directions {
    north, west, east, south
};


#endif //PROJETLOA_SALLE_HPP
