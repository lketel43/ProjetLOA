//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_JEU_HPP
#define PROJETLOA_JEU_HPP

#include "../Personnages/Personnage.hpp"
#include "../Objets/Objet.hpp"
#include "Joueur.hpp"
#include "vector"
#include "Map/Chateau.hpp"
#include <utility>

class Jeu {

private:
    const int nombreDeJoueurs;
    const int nombreJoueurNonAutomatise;
    std::vector<Joueur *> joueurs;
    Chateau *chateau;
    //TODO: create destructor to delete the allocated personnages
    std::vector<std::pair<Personnage *, int>> personnagesDisponiblesEtFrequences;
    Personnage* forge(int);

    //Permet de choisir les personnages pour tous les joueurs
    //Pour les joueurs non automatisés, ils choisissent leur type de personnage
    //Pour les joueurs automatisés, l'ordinateur choisit les personnages tel qu'il y aie le plus de variété possible
    void setPlayers();
    int choosePersonnageAutom();

public:
    //default values are :
    //nombreJoueurNonAutomatise = 1
    //nombreDeJoueurs = 5
    //Chateau (5,5)
    Jeu();
    void lancePartie();

    //Makes number of players, number of automatised players and chateau dimensions customizable
    Jeu(int, int, unsigned int, unsigned int);




};


#endif //PROJETLOA_JEU_HPP
