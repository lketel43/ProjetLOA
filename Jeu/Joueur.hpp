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
    int score;
public:
    Joueur(std::string, bool);
    virtual ~Joueur()=0;

    std::string getName() const;

    Personnage* getPersonnage() const;
    void setPersonnage(Personnage*);
    bool isAutomatise() const;
    bool isPlaced() const;

    void ramasser(Objet*);
    void equiper(Objet*);
    void desequiper(int index);
    Objet* jeterDeEquipement(int index);
    void utiliserClef(Clef*, Jeu*);
    virtual void utiliserPotion(Potion*) const = 0;
    virtual void utiliserPotionPosion(Potion*, const Joueur*) const = 0;
    Objet* jeterDeSac(int index);

    virtual void tourCombat(const Joueur*) const = 0;

    virtual void consulterSacEtEquipement(Jeu*)=0;
    virtual void pickUpObjects(Jeu*)=0;
    virtual int choosePersonnage(std::vector<std::pair<Personnage *, int> >)=0;
    virtual void endTurn(Jeu *) = 0;

    virtual Joueur* mort(Jeu*) = 0;

};


#endif //PROJETLOA_JOUEUR_HPP
