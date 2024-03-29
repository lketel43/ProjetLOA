//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_PERSONNAGE_HPP
#define PROJETLOA_PERSONNAGE_HPP

#include "../Objets/Objet.hpp"
#include <utility>
#include <iostream>
#include <vector>
#include "../Objets/Potion.hpp"

#define MAX_SANTE 100
#define TAILLE_SAC 4
#define TAILLE_EQ 2


class Personnage {

protected:
    Personnage(std::string, int, int, int, int);

private:
    friend std::ostream& operator<<(std::ostream&, Personnage*);
    const std::string nom;
    int sante = 100;
    int habilite = 10;
    std::vector<Objet*> sac;
    std::vector<Objet*> equipement;
    int attaquePhysique;
    int attaqueMagique;
    int resistancePhysique;
    int resistanceMagique;
    std::pair<int, int> position;

public:
    ~Personnage();

    //Subit l'attaque <Physique, Magique> indiquée en tenant en compte la resistance du personnage
    void subitAttaque(int);

    std::string getStats() const;
    std::string getName() const;
    int getSante() const;
    int getHabilete() const;
    int getAttaquePhysique() const;
    int getAttaqueMagique() const;
    int getResistancePhysique() const;
    int getResistanceMagique() const;
    std::pair<int, int> getPosition() const;

    std::vector<Objet*> getSac() const;
    void addToSac(Objet*);
    void removeFromSac(int);
    bool isSacFull() const;
    bool isSacEmpty() const;
    void displaySac() const;

    bool isPlaced() const;

    bool isEquipementFull() const;
    std::vector<Objet*> getEquipement();
    void addToEquipement(Objet*);
    void removeFromEquipement(int);


    void setSante(int);
    void setHabilete(int);
    void setAttaquePhysique(int);
    void setAttaqueMagique(int);
    void setResistancePhysique(int);
    void setResistanceMagique(int);
    void setPosition(int x, int y);

    Potion* hasPotionBoostSante() const;
    Potion* hasPotionPoison() const;
    Potion* hasPotionBoost() const;


};


#endif //PROJETLOA_PERSONNAGE_HPP
