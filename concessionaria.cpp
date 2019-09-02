#include <iostream>
#include "concessionaria.h"

Concessionaria::Concessionaria(string a, int b) {
    nome = a;
    cnpj = b;
    qtd_estoque = 0;
}

std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << endl << "CNPJ: " << c.cnpj << endl << "Quantidade de carros no estoque: " << c.qtd_estoque << endl;
    return o;
}

Concessionaria::~Concessionaria() {

}