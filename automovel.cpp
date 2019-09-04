#include <iostream>
#include <iomanip>
#include "automovel.h"

//Contrutor da Classe
Automovel::Automovel(std::string m, float p, std::string c, Tempo d) {
    marca = m;
    preco = p;
    chassi = c;
    data_criacao = d;
}

//Sobrecarga do operador <<
std::ostream& operator<< (std::ostream &o, Automovel const a) {
    o << "Marca: " << a.marca << std::endl << "Preco: " <<  std::fixed << std::setprecision(2) << a.preco << std::endl << "Chassi: " << a.chassi << std::endl << "Data de criacao: " << a.data_criacao << std::endl;
    return o;
}

//Destrutor da Classe
Automovel::~Automovel() {

}