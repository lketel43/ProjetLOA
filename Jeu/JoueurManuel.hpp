#ifndef PROJETLOA_JOUEUR_MANUEL_HPP
#define PROJETLOA_JOUEUR_MANUEL_HPP

#include "Joueur.hpp"
#include "Combat.hpp"

class JoueurManuel : public Joueur {
    friend class Jeu;
private:
    bool consulterEquipement(Jeu*);
    bool consulterSac(Jeu *);


public:
    JoueurManuel(std::string);
    void tourCombat(const Joueur*) const override;
    void consulterSacEtEquipement(Jeu*) override;
    void pickUpObjects(Jeu*) override;
    int choosePersonnage(std::vector<std::pair<Personnage *, int> >) override;

};

#endif 