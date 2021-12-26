//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_PERSONNAGE_HPP
#define PROJETLOA_PERSONNAGE_HPP

#include "../Objets/Objet.hpp"
#include <utility>
#include <iostream>


class Personnage {

protected:
    Personnage(std::string, int, int, int, int);

private:
    friend std::ostream& operator<<(std::ostream&, Personnage*);
    const std::string nom;
    int sante = 100;
    int habilite = 10;
    Objet *sac[4];
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


};


#endif //PROJETLOA_PERSONNAGE_HPP
