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
    //les joueurs non-automatisés sont placés d'abord dans le vecteur
    std::vector<Joueur *> joueurs;
    Chateau *chateau;
    std::vector<std::pair<Personnage *, int> > personnagesDisponiblesEtFrequences;

    //Input: index d'un type de personnage dans personnagesDisponiblesEtFrequences
    //Output: Nouveau personnage* à un personnage de ce type
    Personnage* forge(int);

    ///CATEGORIE SETUP DU JEU
    //Permet de choisir les personnages pour tous les joueurs
    //Pour les joueurs non automatisés, ils choisissent leur type de personnage
    //Pour les joueurs automatisés, l'ordinateur choisit les personnages tel qu'il y aie le plus de variété possible
    void initJoueurs();

    //Place les joueurs de manière uniforme aléatoire dans le chateau
    void placeJoueurs();

    //TODO: penser à comment rajouter de plus en plus d'objets au fur et a mesure des tours
    //Place objets au début de manière aléatoire dans le chateau
    void placeObjets();

    ///CATEGORIE AUTOMATISATION
    //Fait un choix automatique d'un personnage selon les frequences, pour permettre d'avoir une bonne répartition
    // entre les personnages
    unsigned int choosePersonnageAutom();



public:
    //default values are :
    //nombreJoueurNonAutomatise = 1
    //nombreDeJoueurs = 5
    //Chateau (3,3)
    Jeu();
    void lancePartie();
    ~Jeu();

    //Makes number of players, number of automatised players and chateau dimensions customizable
    Jeu(int, int, unsigned int, unsigned int);


};


#endif //PROJETLOA_JEU_HPP
