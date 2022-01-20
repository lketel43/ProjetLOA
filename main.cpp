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
    Jeu jeu(1, 4, 2, 2);
    jeu.lancePartie();


    return 0;
}

