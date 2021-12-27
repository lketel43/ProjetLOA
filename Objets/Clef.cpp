//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Clef.hpp"

using namespace std;

Clef::Clef(std::string _nom, int _rarete, string _description) : Objet(_nom, _rarete), description(_description) {}

void Clef::utiliser(Jeu *jeu, Joueur *joueur, int x, int y) {
    jeu->moveJoueur(joueur, x, y);
}

string Clef::toString() const{
    return "Nom: " + nom + "\nRareté: " + to_string(rarete) + "\nDescription: " + description + "\n";
}

Clef *Clef::copy() {
    return new Clef(nom, rarete, description);
}
