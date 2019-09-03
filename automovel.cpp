#include "automovel.h"
#include <iostream>

Automovel::Automovel(std::string m, float p, int c, Tempo data(int d, int m, int a)) {
    marca = m;
    preco = p;
    chassi = c;
    // data_criacao = data;
}

// std::ostream& operator<< (std::ostream &o, Automovel const a) {
//     o << "Marca: " << a.marca << std::endl << "Preço: " << a.preco << std::endl << "Chassi: " << a.chassi << "Data de criação: " << a.data_criacao << std::endl;
//     return o;
// }

Automovel::~Automovel() {

}