//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_OBJET_HPP
#define PROJETLOA_OBJET_HPP

#include <iostream>

class Objet {
private:
    friend class ObjectFactory;
protected:
    Objet(std::string, int);
    const std::string nom;
    const int rarete;
    //Factory method
    virtual Objet* copy()=0;
public:
    std::string getNom() const;
    int getRarete() const;
    virtual std::string toString() const =0;
};


#endif //PROJETLOA_OBJET_HPP
