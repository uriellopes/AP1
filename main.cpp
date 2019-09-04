//g++ -Wall -pedantic -g -O0 -o exec main.cpp concessionaria.cpp automovel.cpp tempo.cpp
#include <iostream>
#include "funcoes.h"

int main() {

    //Vector para armazenar as concessionarias
    std::vector<Concessionaria> concessionarias;

    addInfo(concessionarias);

    showMenu(concessionarias);

    return 0;
}