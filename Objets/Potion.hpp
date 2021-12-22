//
// Created by Laila ElKoussy on 12/20/21.
//

#ifndef PROJETLOA_POTION_HPP
#define PROJETLOA_POTION_HPP

#include "Objet.hpp"
#include <vector>

class Potion: public Objet{
    public:
        Potion(std::string, int, float, std::pair<std::string, bool>);
        float getBoost() const;
    private:
        const float boost;
        const std::pair<std::string, bool> type;
};


#endif //PROJETLOA_POTION_HPP
