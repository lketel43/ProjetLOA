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
    std::string nom;
    std::pair<int, int> position;
    int score;
public:
    Joueur(std::string, bool);
    ~Joueur();

    void setPosition(const int&, const int&);
    std::string getName() const;

    Personnage* getPersonnage() const;
    void setPersonnage(Personnage*);
    bool isAutomatise() const;
    std::pair<int, int> getPosition() const;
    bool isPlaced() const;

    void ramasser(Objet*);
    void equiper(Objet*);
    void desequiper(int index);
    Objet* jeterDeEquipement(int index);
    void utiliserClef(Clef*, Jeu*);
    void utiliserPotion(Potion*) const;
    Objet* jeterDeSac(int index);

    virtual void tourCombat(const Joueur*) const = 0;

    virtual void consulterSacEtEquipement(Jeu*)=0;
    virtual void pickUpObjects(Jeu*)=0;
    virtual int choosePersonnage(std::vector<std::pair<Personnage *, int> >)=0;

};


#endif //PROJETLOA_JOUEUR_HPP
