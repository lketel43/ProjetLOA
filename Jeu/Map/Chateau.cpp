
#include "Chateau.hpp"
#include "../../Utilities/Utilities.cpp"
using namespace std;

Chateau::Chateau(unsigned int w, unsigned int l) : width(w), length(l) {

    int count = 0;
    vector<vector<Salle *>> mapInit;
    for (int i = 0; i < w; i++) {
        vector<Salle *> ligne;
        for (int j = 0; j < l; j++) {
            Salle *salle = new Salle(count);
            ligne.push_back(salle);
            count++;
        }
        mapInit.push_back(ligne);
    }
    map = mapInit;
    initializeDirections();
}

void Chateau::initializeDirections() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (i == 0)
                map[i][j]->neighbors[north] = nullptr;
            else
                map[i][j]->neighbors[north] = map[i - 1][j];

            if (i == width - 1)
                map[i][j]->neighbors[south] = nullptr;
            else
                map[i][j]->neighbors[south] = map[i + 1][j];

            if (j == 0)
                map[i][j]->neighbors[west] = nullptr;
            else
                map[i][j]->neighbors[west] = map[i][j - 1];

            if (j == length - 1)
                map[i][j]->neighbors[east] = nullptr;
            else
                map[i][j]->neighbors[west] = map[i][j + 1];
        }
    }
}

unsigned int Chateau::getLength() {
    return length;
}

unsigned int Chateau::getWidth() {
    return width;
}

pair<int, int> Chateau::getEmptiestRoom() {
    pair<int, int> coords;
    int minNumOfPeople;
    coords.first = 0;
    coords.second = 0;
    minNumOfPeople = map[0][0]->numOfPlayers();
    int x_rand = utilities::random(0, width -1);
    int y_rand = utilities::random(0, length -1);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (map[i][j]->numOfPlayers() < minNumOfPeople) {
                minNumOfPeople = map[i][j]->numOfPlayers();
                coords.first = i;
                coords.second = j;
            }
        }
    }

    if(map[x_rand][y_rand]->numOfPlayers() == minNumOfPeople){
        coords.first = x_rand;
        coords.second = y_rand;
    }

    return coords;
}
