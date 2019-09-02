//g++ -Wall -pedantic -g -O0 -o exec main.cpp concessionaria.cpp
#include <iostream>
#include <vector>
#include "concessionaria.h"

using namespace std;

int main() {
    
    vector<Concessionaria> concessionarias;

    concessionarias.push_back(Concessionaria("Fiat", 12121));
    concessionarias.push_back(Concessionaria("Gol", 2323));
    concessionarias.push_back(Concessionaria("Punto", 1223121));

    for(vector<Concessionaria>::iterator i = concessionarias.begin(); i != concessionarias.end(); i++ ) {
        cout << *i << endl;
    }

    for(unsigned int i = 0; i < concessionarias.size(); i++ ) {
        cout << concessionarias[i] << endl;
    }

    return 0;
}