
#ifndef PROJETLOA_CHATEAU_HPP
#define PROJETLOA_CHATEAU_HPP

#include <vector>
#include "Salle.hpp"
#include <utility>

class Jeu;

class Chateau {

private:
    //pour faciliter l'acces à map
    //TODO: ajouter overload à [][] pour peut-être changer ça, ou rendre ça plus elegant
    friend class Jeu;
    unsigned int width;
    unsigned int length;
    std::vector < std::vector<Salle *>> map;

    //initializes the direction pointers of the salles inside the map
    void initializeDirections();

public:
    Chateau(unsigned int, unsigned int);
    unsigned int getLength();
    unsigned int getWidth();
    std::pair<int, int> getEmptiestRoom();

    //TODO: make destructor that deletes all the salles

};

enum directions {
    north, west, east, south
};


#endif //PROJETLOA_CHATEAU_HPP
