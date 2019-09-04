#include <iostream>
#include "concessionaria.h"

Concessionaria::Concessionaria(std::string a, long long int b) {
    nome = a;
    cnpj = b;
    qtd_estoque = 0;
}

std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl << "CNPJ: " << c.cnpj << std::endl << "Quantidade de carros no estoque: " << c.qtd_estoque << std::endl;
    return o;
}

void Concessionaria::adicionarCarro( Automovel c) {
    carros.push_back(c);
    qtd_estoque++;
}

void Concessionaria::showCarros() {
    int j = 0;
    std::cout << "Lista de Carros" << std::endl;
    for(std::vector<Automovel>::iterator i = carros.begin(); i != carros.end(); i++ ) {
        ++j;
        std::cout << "Carro " << j << std::endl << *i;
    }
}

std::string Concessionaria::getNome() {
    return nome;
}

long long int Concessionaria::getCNPJ() {
    return cnpj;
}

Concessionaria::~Concessionaria() {

}