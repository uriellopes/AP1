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
    if( !carros.empty() ) {
        std::cout << std::endl << "=================================" << std::endl;
        std::cout << "Lista de Carros da Concessionaria " << std::endl;
        std::cout << "=================================" << std::endl << std::endl;

        std::cout << std::setw(10) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
        << std::setw(12) << "Preco" << std::setw(8) << "|" 
        << std::setw(13) << "Chassi" << std::setw(7) << "|" 
        << std::setw(11) << "Data" << std::setw(5) << std::endl;
        
        for(std::vector<Automovel>::iterator i = carros.begin(); i != carros.end(); i++ ) {
            ++j;
            if ( j > 9 ) {
                std::cout << "Carro " << j << " |" << *i;
            } else {
                std::cout << std::setw(6) << "Carro " << j << "  |" << *i << std::endl;
            }
        }
    } else {
        std::cout << "Nenhum carro cadastrado" << std::endl << std::endl;
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