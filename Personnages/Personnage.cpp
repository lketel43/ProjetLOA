//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Personnage.hpp"

using namespace std;


Personnage::Personnage(string n, int aP, int aM, int rP, int rM): nom(n), attaquePhysique(aP), attaqueMagique(aM), resistanceMagique(rM), resistancePhysique(rP) { }

//TODO: a voir si on change la fonction attaque pour prendre en compte habileté, santé etc.
pair<int, int> Personnage::attaque(){
    pair<int,int> pair (attaquePhysique, attaqueMagique);
    return pair;
}

void Personnage::subitAttaque(pair<int, int> & pair) {

    //Prevoie si la resistance  est superieure à l'attaque
    sante -= ((pair.first - resistancePhysique) > 0)? pair.first - resistancePhysique : 0;
    sante -= ((pair.second - resistanceMagique) > 0)? pair.second - resistanceMagique : 0;

}