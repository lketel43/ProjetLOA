//
// Created by Laila ElKoussy on 12/20/21.
//

#include "Chateau.hpp"

using namespace std;

Chateau::Chateau(int w, int l) : width(w), length(l) {

    int count = 0;
    vector <vector<Salle *>> mapInit;
    for (int i = 0; i < w; i++) {
        vector < Salle * > ligne;
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
        for (int j = 0; i < length; j++) {
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
