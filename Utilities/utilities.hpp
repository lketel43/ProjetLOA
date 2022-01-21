//
// Created by Laila ElKoussy on 1/18/22.
//

#ifndef PROJETLOA_UTILITIES_HPP
#define PROJETLOA_UTILITIES_HPP

#include <cmath>
#include <vector>

class utilities{
private:
    static bool isNumber(const std::string& str);
public:
    static int bernouilli(double param);
    static void display(const std::string& text);
    static unsigned int validateRange(int i, int j);
    static int random(int i, int j);
    static int calcPercentage(int, int);
    template<typename T> static std::vector<T> filtre(bool (*func)(T), std::vector<T>);
};

#endif //PROJETLOA_UTILITIES_HPP
