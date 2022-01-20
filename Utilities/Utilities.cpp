#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "utilities.hpp"


using namespace std;

//generates random number in range [i,j]
int utilities::random(int i, int j) {
    int difference = 1 + j - i;
    return (rand() % difference + i);

}

bool utilities::isNumber(const string &str) {
    for (char const &c: str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

//checks if x, in range [i,j], does validation and returns correct value entered
unsigned int utilities::validateRange(int i, int j) {
    string entered;
    int enteredInt;
    bool unvalidated = false;
    cin >> entered;

    do {
        if (!isNumber(entered)) {
            display("Vous avez entré une valeur non-conforme. \n");
            display("Entrez une valeur entre " + to_string(i) + " et " + to_string(j) + ".\n");
            cin >> entered;
            unvalidated = true;
        } else {
            enteredInt = stoi(entered);
            if (enteredInt > j || enteredInt < i) {
                cout << "Vous avez entré une valeur non-conforme. " << endl
                     << "Entrez une valeur entre " << i << " et " << j << "." << endl;
                cin >> entered;
                unvalidated = true;
            } else {
                unvalidated = false;
            }

        }

    } while (unvalidated);

    return enteredInt;
}

//displays line then waits for a bit for better readability
void utilities::display(const string &text) {
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    cout << text;
    //sleep_for(seconds(1));
}

int utilities::bernouilli(double param) {
    double borneD = 1000000.0;
    int borneI = 1000000;
    double tirage = (rand() % borneI) / borneD;
    if (tirage < param) {
        return 1;
    }
    return 0;
}

int utilities::calcPercentage(int stat, int per){
    double boost = ((double) per / 100.0) * (double) stat;
    return floor(boost) + 1;
}


