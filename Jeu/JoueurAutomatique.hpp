#ifndef PROJETLOA_JOUEUR_AUTOMATIQUE_HPP
#define PROJETLOA_JOUEUR_AUTOMATIQUE_HPP

#include "Joueur.hpp"
#include "Combat.hpp"

class JoueurAutomatique : public Joueur{
public:
    JoueurAutomatique(std::string);
    ~JoueurAutomatique() override;
    void tourCombat(const Joueur*) const override;
    void consulterSacEtEquipement(Jeu*) override;
    void pickUpObjects(Jeu*) override;
    void utiliserPotion(Potion*) const override;
    void utiliserPotionPosion(Potion*, const Joueur*) const override;
    int choosePersonnage(std::vector<std::pair<Personnage *, int> >) override;
    Joueur* mort(Jeu*) override;
    void endTurn(Jeu *) override;

};

#endif 