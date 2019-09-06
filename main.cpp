//g++ -std=c++11 -Wall -pedantic -g -O0 -o exec main.cpp funcoes.cpp concessionaria.cpp automovel.cpp tempo.cpp
#include <iostream>
#include "funcoes.h"

int main() {

    //Vector para armazenar as concessionárias
    std::vector<Concessionaria> concessionarias;

    //Adicionar informações iniciais no código para testes
    addInfo(concessionarias);

    //Mostrar menu principal
    showMenu(concessionarias);

    return 0;
}