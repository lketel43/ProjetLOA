
#ifndef PROJETLOA_CHATEAU_HPP
#define PROJETLOA_CHATEAU_HPP

#include <vector>
#include "Salle.hpp"
#include <utility>

class Jeu;

class Chateau {

private:
    //pour faciliter l'acces à map
    friend class Jeu;
    unsigned int width;
    unsigned int length;
    std::vector < std::vector<Salle *>> map;
    void placeDansSalle(std::pair<unsigned int,unsigned int>, Objet*);
    //initializes the direction pointers of the salles inside the map
    void initializeDirections();

public:
    Chateau(unsigned int, unsigned int);
    ~Chateau();
    unsigned int getLength();
    unsigned int getWidth();
    std::pair<int, int> getEmptiestRoom();
    void display();
    void display(std::pair<int,int>);
    std::pair<int,int> getSalleCoordinates(int) const;

};



#endif //PROJETLOA_CHATEAU_HPP
