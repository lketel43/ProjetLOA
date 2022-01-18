#ifndef PROJETLOA_JOUEUR_AUTOMATIQUE_HPP
#define PROJETLOA_JOUEUR_AUTOMATIQUE_HPP

#include "Joueur.hpp"
#include "Combat.hpp"

class JoueurAutomatique : public Joueur{
public:
    JoueurAutomatique(std::string);
    ~JoueurAutomatique() override;
    void tourCombat(const Joueur*) const override;
    //TODO: IMPLEMENT BELOW FUNCTION
    void consulterSacEtEquipement(Jeu*) override;
    //TODO: IMPLEMENT BELOW FUNCTION
    void pickUpObjects(Jeu*) override;
    int choosePersonnage(std::vector<std::pair<Personnage *, int> >) override;
    void endTurn(Jeu *) override;

};

#endif 