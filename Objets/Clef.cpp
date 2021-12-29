//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Clef.hpp"

Clef::Clef(std::string _nom, int _rarete): Objet(_nom, _rarete, false, true, 2) {}

void Clef::utiliser(Jeu* jeu, Joueur * joueur, int x, int y) {
    jeu->moveJoueur(joueur, x, y);

}

