//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_PERSONNAGE_HPP
#define PROJETLOA_PERSONNAGE_HPP

#include "../Objets/Objet.hpp"
#include <utility>
#include <iostream>

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
    Objet *sac[TAILLE_SAC];
    Objet *equipement[TAILLE_EQ];
    int attaquePhysique;
    int attaqueMagique;
    int resistancePhysique;
    int resistanceMagique;

public:
    //Retourne les dégats commits <Physique, Magique>
    std::pair<int, int> attaque();

    //Subit l'attaque <Physique, Magique> indiquée en tenant en compte la resistance du personnage
    void subitAttaque(std::pair<int, int> &);

    std::string getStats();
    std::string getName();
    Objet** getSac();
    void setSac(int, Objet*);
    bool isSacFull();
    bool isEquipementFull();
    Objet** getEquipement();
    void setEquipement(int, Objet*);

    void setSante(int);
    void setHabilete(int);
    void setAttatquePhysique(int);
    void setAttaqueMagique(int);
    void setResistancePhysique(int);
    void setResistanceMagique(int);


};


#endif //PROJETLOA_PERSONNAGE_HPP
