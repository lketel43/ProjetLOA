//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_JEU_HPP
#define PROJETLOA_JEU_HPP

#include <vector>
#include <stdexcept>
#include "Map/Chateau.hpp"
#include "../Objets/ObjectFactory.hpp"
#include "../Personnages/Personnage.hpp"


class Combat;
class Jeu {

private:
    const unsigned int nombreDeJoueurs;
    const unsigned int nombreJoueurNonAutomatise;
    ObjectFactory* objectFactory;
    std::vector<Objet*> objetsPossibles;
    //les joueurs non-automatisés sont placés d'abord dans le vecteur
    std::vector<Joueur*> joueurs;
    Chateau *chateau;
    std::vector<std::pair<Personnage *, int> > personnagesDisponiblesEtFrequences;

    bool partieFinie = false;

    //Input: index d'un type de personnage dans personnagesDisponiblesEtFrequences
    //Output: Nouveau personnage* à un personnage de ce type
    Personnage* forge(int);

    ///CATEGORIE SETUP DU JEU
    //Permet de choisir les personnages pour tous les joueurs
    //Pour les joueurs non automatisés, ils choisissent leur type de personnage
    //Pour les joueurs automatisés, l'ordinateur choisit les personnages tel qu'il y aie le plus de variété possible
    void initJoueurs();
    void initVecteurPersonnages();
    void initVecteursJoueurs();
    //Place les joueurs de manière uniforme aléatoire dans le chateau
    void placeJoueurs();
    //Place objets au début de manière aléatoire dans le chateau
    void placeObjets();

    ///CATEGORIE DEROULEMENT JEU
    void moveJoueur(Joueur*, int x, int y);
    void renforcerJoueursAutomatises();
    friend class Clef;
    void tour(Joueur *);

public:
    //default values are :
    //nombreJoueurNonAutomatise = 1
    //nombreDeJoueurs = 5
    //Chateau (4,4)
    Jeu();
    std::vector<Joueur*> getJoueurs() const;
    void removeJoueur(Personnage*);
    void displayMap(Joueur*) const;
    unsigned int getNumberOfSalles() const;
    bool lancePartie();
    std::pair<int, int> getSallePosition(int num) const;
    void placerDansSalle(std::pair<int,int>, Objet*);
    Salle* getSalle(std::pair<unsigned int, unsigned int>) const;
    ~Jeu();
    void moveJoueurtoSalle(Joueur*, Salle*);
    void spotLast();

    //Makes number of players, number of automatised players and chateau dimensions customizable
    Jeu(int, int, unsigned int, unsigned int);


};


#endif //PROJETLOA_JEU_HPP
