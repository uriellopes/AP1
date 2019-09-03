#include <iostream>
#include "concessionaria.h"

Concessionaria::Concessionaria(std::string a, int b) {
    nome = a;
    cnpj = b;
    qtd_estoque = 0;
}

std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl << "CNPJ: " << c.cnpj << std::endl << "Quantidade de carros no estoque: " << c.qtd_estoque << std::endl;
    return o;
}

Concessionaria::~Concessionaria() {

}