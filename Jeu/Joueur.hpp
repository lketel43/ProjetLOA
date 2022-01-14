//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_JOUEUR_HPP
#define PROJETLOA_JOUEUR_HPP

#include "../Personnages/Personnage.hpp"
#include "../Objets/Clef.hpp"
#include "../Objets/Potion.hpp"

class Salle;
class Jeu;

class Joueur {
private:
    friend std::ostream& operator<<(std::ostream&, Joueur*);

protected:
    Personnage * personnage;
    const bool automatise;
    const std::string nom;
    std::pair<int, int> position;
    int score;
public:
    Joueur(std::string, Personnage*, bool);
    ~Joueur();
    void setPosition(const int&, const int&);
    //returns true if player is dead
    std::string getName() const;
    bool updateScore();
    int getScore() const;
    bool isAutomatise() const;
    std::pair<int, int> getPosition() const;
    bool isPlaced() const;

    void ramasser(Objet*);
    void equiper(Objet*);
    void desequipper(int index);
    Objet* jeterDeEquipement(int index);
    void utiliserClef(Clef*, Jeu*);
    void utiliserPotion(Potion*);
    Objet* jeterDeSac(int index);
    virtual void consulterSacEtEquipement(Jeu*)=0;

};


#endif //PROJETLOA_JOUEUR_HPP
