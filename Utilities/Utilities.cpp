#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>


using namespace std;

namespace utilities {

    //generates random number in range [i,j]
    static int random(int i, int j) {
        int difference = 1 + j - i;
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

    //displays line then waits for a bit for better readability
    static void display(const string& text){
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds

        cout<<text;
        //sleep_for(seconds(1));
    }

    static int bernouilli(float param){
        int borne = 1000000;
        float tirage = (rand() % borne) / borne;
        if(tirage < param){
            return 1;
        }
        return 0;
    }


}