//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_JOUEUR_HPP
#define PROJETLOA_JOUEUR_HPP

#include "../Personnages/Personnage.hpp"

class Salle;
class Jeu;
class Clef;
class Potion;

class Joueur {
protected:
    Personnage * personnage;
    const bool automatise;
    const std::string nom;
    std::pair<int, int> position;
    int score;
    friend std::ostream& operator<<(std::ostream&, Joueur*);

public:
    Joueur(std::string, Personnage*, bool);
    ~Joueur();
    void setPosition(const int&, const int&);
    //returns true if player is dead
    std::string getName() const;
    //bool updateScore();
    //int getScore() const;
    Personnage* getPersonnage() const;
    bool isAutomatise() const;
    std::pair<int, int> getPosition() const;
    bool isPlaced() const;

    void ramasser(Objet*);
    void equiper(Objet*);
    void desequipper(int index);
    Objet* jeterDeEquipement(int index);
    void utiliserClef(Clef*, Jeu*);
    void utiliserPotion(Potion*) const;
    Objet* jeterDeSac(int index);

    virtual void tourCombat(const Joueur*) const = 0;




};


#endif //PROJETLOA_JOUEUR_HPP
