//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_JOUEUR_HPP
#define PROJETLOA_JOUEUR_HPP

#include "../Personnages/Personnage.hpp"

class Joueur {
private:
    Personnage * personnage;
    const bool automatise;
    const std::string nom;
    std::pair<int, int> position;
    int score;
    friend std::ostream& operator<<(std::ostream&, Joueur*);

public:
    Joueur(std::string, Personnage*, bool);
    void setPosition(const int&, const int&);
    //returns true if player is dead
    std::string getName() const;
    bool updateScore();
    int getScore() const;
    std::pair<int, int> getPosition() const;
    bool isPlaced() const;
    bool isAutomatise() const;
    ~Joueur();



};


#endif //PROJETLOA_JOUEUR_HPP
