//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_PERSONNAGE_HPP
#define PROJETLOA_PERSONNAGE_HPP

#include "../Objets/Objet.hpp"
#include <utility>
#include <iostream>
#include <vector>

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

public:
    ~Personnage();
    //Retourne les dégats commits <Physique, Magique>
    std::pair<int, int> attaque();

    //Subit l'attaque <Physique, Magique> indiquée en tenant en compte la resistance du personnage
    void subitAttaque(int);

    std::string getStats();
    std::string getName();
    int getSante() const;
    int getAttaquePhysique() const;
    int getAttaqueMagique() const;
    int getResistancePhysique() const;
    int getResistanceMagique() const;

    std::vector<Objet*> getSac();
    void addToSac(Objet*);
    void removeFromSac(int);
    bool isSacFull();
    void displaySac();

    bool isEquipementFull();
    std::vector<Objet*> getEquipement();
    void addToEquipement(Objet*);
    void removeFromEquipement(int);

    void setSante(int);
    void setHabilete(int);
    void setAttaquePhysique(int);
    void setAttaqueMagique(int);
    void setResistancePhysique(int);
    void setResistanceMagique(int);


};


#endif //PROJETLOA_PERSONNAGE_HPP
