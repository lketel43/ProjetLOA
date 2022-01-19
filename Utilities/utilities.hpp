//
// Created by Laila ElKoussy on 1/18/22.
//

#ifndef PROJETLOA_UTILITIES_HPP
#define PROJETLOA_UTILITIES_HPP

class utilities{
private:
    static bool isNumber(const std::string& str);
public:
    static int bernouilli(float param);
    static void display(const std::string& text);
    static int validateRange(int i, int j);
    static int random(int i, int j);
};

#endif //PROJETLOA_UTILITIES_HPP
