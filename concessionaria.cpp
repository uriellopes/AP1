#include <iostream>
#include "concessionaria.h"

//Construtor de concessionaria
Concessionaria::Concessionaria(std::string a, long long int b) {
    nome = a;
    cnpj = b;
    qtd_estoque = 0;
}

//Sobrecarga do operador << de concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl << "CNPJ: " << c.cnpj << std::endl << "Quantidade de carros no estoque: " << c.qtd_estoque << std::endl;
    return o;
}

//Funcao para adicionar carros na concessionaria
void Concessionaria::adicionarCarro( Automovel c) {
    carros.push_back(c);
    qtd_estoque++;
}

//Funcao para mostrar todos os carros de uma concessionaria
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

//Getter do atributo nome
std::string Concessionaria::getNome() {
    return nome;
}

//Getter do atributo cnpj
long long int Concessionaria::getCNPJ() {
    return cnpj;
}

//Funcao para aumentar o preco em uma certa % de todos os carros
void Concessionaria::aumentarPreco(float value) {
    float percent = value/100;
    for(unsigned int i = 0; i < carros.size(); i++ ) {
        carros[i].setPreco(carros[i].getPreco() + (carros[i].getPreco() * percent));
    }
}

void Concessionaria::listarCarrosRecentes() {
    time_t atual;
    time(&atual);
    tm * tempo = localtime(&atual);

    Tempo hoje = Tempo(tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900);

    int j = 0;
    if( !carros.empty() ) {
        std::cout << std::endl << "=================================" << std::endl;
        std::cout << "Lista de Carros da Concessionaria " << std::endl;
        std::cout << "=================================" << std::endl << std::endl;

        std::cout << std::setw(10) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
        << std::setw(12) << "Preco" << std::setw(8) << "|" 
        << std::setw(13) << "Chassi" << std::setw(7) << "|" 
        << std::setw(11) << "Data" << std::setw(5) << std::endl;

        for(unsigned int i = 0; i < carros.size(); i++ ) {
            if( (hoje.getQtdDias() - carros[i].getQtdDias()) < 90 ) {
                ++j;
                if ( j > 9 ) {
                    std::cout << "Carro " << j << " |" << carros[i];
                } else {
                    std::cout << std::setw(6) << "Carro " << j << "  |" << carros[i] << std::endl;
                }
            }
        }
    } else {
        std::cout << "Nenhum carro encontrado" << std::endl << std::endl;
    }
}

//Destrutor de concessionaria
Concessionaria::~Concessionaria() {

}