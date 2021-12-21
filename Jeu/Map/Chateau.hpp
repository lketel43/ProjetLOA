
#ifndef PROJETLOA_CHATEAU_HPP
#define PROJETLOA_CHATEAU_HPP

#include <vector>
#include "Salle.hpp"

class Chateau {

private:
    unsigned int width;
    unsigned int length;
    std::vector < std::vector<Salle *>> map;

    //initializes the direction pointers of the salles inside the map
    void initializeDirections();

public:
    Chateau(unsigned int, unsigned int);

    //TODO: make destructor that deletes all the salles

};

enum directions {
    north, west, east, south
};


#endif //PROJETLOA_CHATEAU_HPP
