//
// Created by Laila ElKoussy on 1/18/22.
//

#ifndef PROJETLOA_UTILITIES_HPP
#define PROJETLOA_UTILITIES_HPP

#include <cmath>

class utilities{
private:
    static bool isNumber(const std::string& str);
public:
    static int bernouilli(double param);
    static void display(const std::string& text);
    static unsigned int validateRange(int i, int j);
    static int random(int i, int j);
    static int calcPercentage(int, int);
};

#endif //PROJETLOA_UTILITIES_HPP
