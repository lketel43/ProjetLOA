//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_OBJET_HPP
#define PROJETLOA_OBJET_HPP

#include <iostream>

#define IDTYPE_ARME 0
#define IDTYPE_POTION 1
#define IDTYPE_CLEF 2

class Objet {
private:
    friend class ObjectFactory;
protected:
    const std::string nom;
    const int rarete;
    const bool equipable;
    const bool utilisable;
    const int idType;
    Objet(std::string, int, bool, bool, int);

    //Factory method
    virtual Objet* copy()=0;
public:
    virtual ~Objet() =0;
    std::string getNom() const;
    int getRarete() const;
    int getIdType() const;
    bool isEquipable();
    bool isUtilisable();
    virtual bool isArmeDattaque() const=0;
    virtual bool isArmeDeDefense() const=0;
    virtual void display() const =0;
    virtual std::string toString() const =0;

};


#endif //PROJETLOA_OBJET_HPP
