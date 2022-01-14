#ifndef PROJETLOA_JOUEUR_MANUEL_HPP
#define PROJETLOA_JOUEUR_MANUEL_HPP

#include "Joueur.hpp"

class JoueurManuel : public Joueur {
    friend class Jeu;
private:
    void consulterEquipement();
    bool consulterSac(Jeu *);


public:
    JoueurManuel(std::string, Personnage*);
    void consulterSacEtEquipement(Jeu*) override;


};

#endif 