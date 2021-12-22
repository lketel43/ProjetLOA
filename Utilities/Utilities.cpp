#include <iostream>
#include <cstdlib>


using namespace std;

namespace utilities {

    //generates random number in range [i,j]
   static  int random(int i, int j) {
        int difference = 1+ j - i;
        return (rand() % difference + i);

    }

    //checks if x, in range [i,j], does validation and returns correct value entered
    static int validateRange(int x, int i, int j) {
       int entered = x;

        do {
            if (entered > j || entered < i) {
                cout << "Vous avez entré une valeur non-conforme. " << endl
                     << "Entrez une valeur entre " << i << " et " << j << "." << endl;
                cin >> entered;
            }

        } while ((entered > j || entered < i));

        return entered;
    }
}