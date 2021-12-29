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
     Objet(std::string, int, bool, bool, int);
    const std::string nom;
    const int rarete;
    const bool equipable;
    const bool utilisable;
    const int idType;
    //Factory method
    virtual Objet* copy()=0;
public:
    std::string getNom() const;
    int getRarete() const;
    virtual void display() const =0;

    int getIdType() const;
    bool isEquipable();
    bool isUtilisable();

};


#endif //PROJETLOA_OBJET_HPP
