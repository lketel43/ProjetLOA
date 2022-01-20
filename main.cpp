//
// Created by Laila ElKoussy on 12/20/21.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Jeu/Jeu.hpp"
#include "Utilities/utilities.hpp"

using namespace std;

int main() {
    //TODO: make sure number of players is not > the number of chambers
    srand(static_cast<unsigned int>(time(nullptr)));
    int length, width, ennemis, joueurManuel = 1;
    unsigned int choix;
    bool repeat;
    utilities::display("Bienvenu au Jeu de chateau révolutionnaire et addictif!\n");
    utilities::display("Le principe du jeu est simple: vaincre tous les ennemis. \n");
    utilities::display("Vous serez placé dans un château.\n");
    utilities::display(
            "Dans ce château, vous trouverez des armes, des potions, des clefs de téléportation. Mais aussi....");
    utilities::display("DES ENNEMIS!\n");
    Jeu * jeu;
    do {
        utilities::display("Avant de vous lancer dans le jeu, veuillez choisir le niveau de difficulté du jeu:\n");
        utilities::display("1. Niveau facile: château de taille 3x3, 8 ennemis. \n");
        utilities::display("2. Niveau intermédiaire: château de taille 3x3, 16 ennemis. \n");
        utilities::display("3. Niveau expert: château de taille 4x4, 32 ennemis.\n");

        choix = utilities::validateRange(1, 3);
        switch (choix) {
            case 1:
                length = width = 3;
                ennemis = 8;
                break;
            case 2:
                length = width = 3;
                ennemis = 16;
                break;
            case 3:
                length = width = 4;
                ennemis = 32;
                break;
            default:
                cout << "ERROR IN CHOICE VALIDATION" << endl;

        }
        jeu = new Jeu (joueurManuel, joueurManuel + ennemis, length, width);
        repeat = jeu->lancePartie();
        delete jeu;
    } while (repeat);


    return 0;
}

