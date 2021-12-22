//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_OBJET_HPP
#define PROJETLOA_OBJET_HPP

#include <iostream>

class Objet {
    private:
        const std::string nom; 
        const int rarete;
    public:
        Objet(std::string, int);
        std::string getNom() const;
        int getRarete() const;


};


#endif //PROJETLOA_OBJET_HPP
