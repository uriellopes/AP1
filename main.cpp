//g++ -Wall -pedantic -g -O0 -o exec main.cpp concessionaria.cpp automovel.cpp tempo.cpp
#include <iostream>
#include <vector>
#include "concessionaria.h"

//Funçao para checar se o ano inserido é bissexto
bool checkBissexto(int &ano) {
    return (ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0);
}

//Função para validar se a data inserida é válida
bool validarData(int d, int m, int a) {
    int meses[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if( checkBissexto(a) ) {
        meses[1] = 29;
    }
    bool anoCheck = a > 0;
    bool mesCheck = m >= 1 && m <= 12;
    bool diaCheck = d >= 1 && d <= meses[m-1];

    return anoCheck && mesCheck && diaCheck;
}

int main() {

    std::vector<Concessionaria> concessionarias;

    concessionarias.push_back(Concessionaria("Concessionaria 1", 12121));
    // concessionarias.push_back(Concessionaria("Concessionaria 2", 2323));
    // concessionarias.push_back(Concessionaria("Concessionaria 3", 1223121));

    concessionarias[0].adicionarCarro(Automovel("Fiat", 20000.00, "219301293", Tempo(2, 3, 2019)));
    std::cout << concessionarias[0] << std::endl;
    concessionarias[0].showCarros();


    // for(std::vector<Concessionaria>::iterator i = concessionarias.begin(); i != concessionarias.end(); i++ ) {
    //     std::cout << *i << std::endl;
    // }

    // for(unsigned int i = 0; i < concessionarias.size(); i++ ) {
    //     std::cout << concessionarias[i] << std::endl;
    // }

    // int dia, mes, ano;

    // std::cin >> dia;
    // std::cin >> mes;
    // std::cin >> ano;

    // // Tempo data = Tempo(dia, mes, ano);

    // Automovel c = Automovel("Fiat", 20000.00, "219301293", Tempo(dia, mes, ano));

    // std::cout << std::endl;
    // std::cout << c << std::endl;
    //std::cout << c.data_criacao << std::endl;

    // std::cout << validarData(dia, mes, ano) << std::endl;
    // std::cout << "teste" << std::endl;

    // Tempo data = Tempo(dia,mes,ano);

    // std::cout << data << std::endl;


    // vector<Concessionaria> concessionarias;

    // concessionarias.push_back(Concessionaria("Fiat", 12121));
    // concessionarias.push_back(Concessionaria("Gol", 2323));
    // concessionarias.push_back(Concessionaria("Punto", 1223121));

    // for(vector<Concessionaria>::iterator i = concessionarias.begin(); i != concessionarias.end(); i++ ) {
    //     cout << *i << endl;
    // }

    // for(unsigned int i = 0; i < concessionarias.size(); i++ ) {
    //     cout << concessionarias[i] << endl;
    // }

    return 0;
}