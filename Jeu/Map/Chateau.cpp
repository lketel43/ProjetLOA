
#include "Chateau.hpp"
#include "../../Utilities/utilities.hpp"
#include <iomanip>

using namespace std;

Chateau::Chateau(unsigned int w, unsigned int l) : width(w), length(l) {

    int count = 1;
    vector<vector<Salle *> > mapInit;
    for (unsigned int i = 0; i < w; i++) {
        vector<Salle *> ligne;
        for (unsigned int j = 0; j < l; j++) {
            Salle *salle = new Salle(count);
            ligne.push_back(salle);
            count++;
        }
        mapInit.push_back(ligne);
    }
    map = mapInit;
    initializeDirections();
}


pair<int, int> Chateau::getSalleCoordinates(int num) const {
    pair<int, int> pair1;
    if (map[(num - 1) / length][(num - 1) % length]->getId() != num) {
        cout << "ERROR IN FETCHING PROPER SALLE COORDINATES\n";
        pair1.first = -1;
        pair1.second = -1;
    } else {
        pair1.first = (num - 1) / length;
        pair1.second = (num - 1) % length;
    }
    return pair1;
}

void Chateau::initializeDirections() {
    for (unsigned int i = 0; i < width; i++) {
        for (unsigned int j = 0; j < length; j++) {
            if (i != 0)
                map[i][j]->neighbors.push_back(map[i - 1][j]);

            if (i != width - 1)
                map[i][j]->neighbors.push_back(map[i + 1][j]);

            if (j != 0)
                map[i][j]->neighbors.push_back(map[i][j - 1]);

            if (j != length - 1)
                map[i][j]->neighbors.push_back(map[i][j + 1]);
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
    int x_rand = utilities::random(0, width - 1);
    int y_rand = utilities::random(0, length - 1);

    for (unsigned int i = 0; i < width; i++) {
        for (unsigned int j = 0; j < length; j++) {
            if (map[i][j]->numOfPlayers() < minNumOfPeople) {
                minNumOfPeople = map[i][j]->numOfPlayers();
                coords.first = i;
                coords.second = j;
            }
        }
    }

    if (map[x_rand][y_rand]->numOfPlayers() == minNumOfPeople) {
        coords.first = x_rand;
        coords.second = y_rand;
    }

    return coords;
}

void Chateau::display() {
    int currSalleId;
    cout << "----------------------------------" << endl;
    for (unsigned int i = 0; i < length; i++) {
        if (i > 0)
            cout << "----  ------  ------  ------  ----" << endl;
        for (int k = 0; k < 3; k++) {
            for (unsigned int j = 0; j < width; j++) {
                currSalleId = map[i][j]->getId();
                if (k == 1)
                    if (j == 0)
                        if (currSalleId < 10)
                            cout << "|   " << currSalleId << "   ";
                        else
                            cout << "|   " << currSalleId << "  ";
                    else if (currSalleId < 10)
                        cout << "    " << currSalleId << "   ";
                    else
                        cout << "    " << currSalleId << "  ";

                else
                    cout << "|       ";

                if (j == width - 1) {
                    if (currSalleId < 10) {
                        cout << "  |";
                    } else {
                        cout << " |";
                    }
                }

            }
            cout << endl;
        }
//        cout << endl;

    }
    cout << "----------------------------------" << endl;
}

void Chateau::display(pair<int, int> position) {
    int salleId = map[position.first][position.second]->getId();
    int currSalleId;

    cout << "----------------------------------" << endl;
    for (unsigned int i = 0; i < length; i++) {
        if (i > 0)
            cout << "----  ------  ------  ------  ----" << endl;
        for (int k = 0; k < 3; k++) {
            for (unsigned int j = 0; j < width; j++) {
                currSalleId = map[i][j]->getId();
                if (k == 1) {
                    if (j == 0)
                        if (currSalleId < 10 || salleId == currSalleId)
                            if (currSalleId == salleId)
                                cout << "|   " << "x" << "   ";
                            else
                                cout << "|   " << currSalleId << "   ";
                        else
                            cout << "|   " << currSalleId << "  ";
                    else if (currSalleId < 10 || salleId == currSalleId)
                        if (currSalleId == salleId)
                            cout << "    " << "x" << "   ";
                        else
                            cout << "    " << currSalleId << "   ";
                    else
                        cout << "    " << currSalleId << "  ";
                } else {
                    cout << "|       ";
                }

                if (j == width - 1){
                    if (currSalleId < 10)
                        cout << "  |";
                    else cout << " |";
                }

            }
            cout << endl;
        }

    }
    cout << "----------------------------------" << endl;
}


Chateau::~Chateau() {
    for (unsigned int i = 0; i < map.size(); i++) {
        for (unsigned int j = 0; j < map[i].size(); j++) {
            delete map[i][j];
        }
    }
}

void Chateau::placeDansSalle(std::pair<unsigned int, unsigned int> salleCoords, Objet *object) {
    if (salleCoords.first > width || salleCoords.second > length) {
        cout << "ERROR WITH SALLE COORDINATES\n";
        return;
    }
    map[salleCoords.first][salleCoords.second]->placeObject(object);
}
