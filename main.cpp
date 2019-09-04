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

//Função para adicionar dados inciais quando o programa for executado
void addInfo(std::vector<Concessionaria> &concessionarias) {
    //Criando concessionários para ter dados iniciais
    concessionarias.push_back(Concessionaria("Concessionaria 1", 12121));
    concessionarias.push_back(Concessionaria("Concessionaria 2", 2323));
    concessionarias.push_back(Concessionaria("Concessionaria 3", 1223121));

    //Dados iniciais para as concessionárias 
    concessionarias[0].adicionarCarro(Automovel("Toyota", 20000.00, "AAAAAAAAAAA", Tempo(2, 1, 2019)));
    concessionarias[0].adicionarCarro(Automovel("Volkswagen", 15000.00, "BBBBBBBBBB", Tempo(17, 3, 2018)));
    concessionarias[0].adicionarCarro(Automovel("Ford", 18000.50, "CCCCCCCCCC", Tempo(31, 3, 2018)));
    concessionarias[0].adicionarCarro(Automovel("Nissan", 50500.00, "DDDDDDDDDD", Tempo(28, 8, 2019)));
    concessionarias[0].adicionarCarro(Automovel("Hyundai", 78800.00, "EEEEEEEEEE", Tempo(14, 7, 2019)));

    concessionarias[1].adicionarCarro(Automovel("Chevrolet", 16500.00, "FFFFFFFFFF", Tempo(1, 9, 2019)));
    concessionarias[1].adicionarCarro(Automovel("Kia", 32000.00, "GGGGGGGGGG", Tempo(17, 8, 2018)));
    concessionarias[1].adicionarCarro(Automovel("Mercedes-Benz", 45900.50, "HHHHHHHHHH", Tempo(31, 7, 2019)));
    concessionarias[1].adicionarCarro(Automovel("Renault", 69999.90, "IIIIIIIIII", Tempo(30, 6, 2019)));

    concessionarias[2].adicionarCarro(Automovel("Audi", 3600.00, "JJJJJJJJJJ", Tempo(29, 8, 2019)));
    concessionarias[2].adicionarCarro(Automovel("Peugeot", 7000.00, "KKKKKKKKKK", Tempo(17, 3, 2018)));
    concessionarias[2].adicionarCarro(Automovel("BMW", 125400.50, "LLLLLLLLLL", Tempo(31, 3, 2017)));
}

void showMenu( std::vector<Concessionaria> &concessionarias, int &escolha ) {
    std::cout << "Escolha uma Concessionaria ou Crie uma nova" << std::endl << std::endl;
    std::cout << "1 - Criar nova Concessionaria" << std::endl;
    int opcoes = 1;
    for(unsigned int i = 0; i < concessionarias.size(); i++ ) {
        std::cout << i + 2 << " - Selecionar Concessionaria " << concessionarias[i].getNome() << std::endl;
        opcoes++;
    }

    std::cout << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cin >> escolha;

    if( escolha < 0 || escolha > opcoes ) {        
        std::cout << "==============================" << std::endl;
        std::cout << std::endl << "   Digite uma opcao valida!   " << std::endl << std::endl;
        std::cout << "==============================" << std::endl;
    } else {
        switch (escolha)
        {
        case 0:
            break;
        case 1:
            break;
        default:
            break;
        }
    }
}

int main() {

    //Vector para armazenar as concessionarias
    std::vector<Concessionaria> concessionarias;

    addInfo(concessionarias);

    int escolha;

    do {
        showMenu(concessionarias, escolha);
    } while( escolha != 0);

    // for(unsigned int i = 0; i < concessionarias.size(); i++ ) {
    //     std::cout << concessionarias[i] << " " << i << std::endl;
    // }

    // //Criando concessionários para ter dados iniciais
    // concessionarias.push_back(Concessionaria("Concessionaria 1", 12121));
    // concessionarias.push_back(Concessionaria("Concessionaria 2", 2323));
    // concessionarias.push_back(Concessionaria("Concessionaria 3", 1223121));

    // //Dados iniciais para as concessionárias 
    // concessionarias[0].adicionarCarro(Automovel("Toyota", 20000.00, "AAAAAAAAAAA", Tempo(2, 1, 2019)));
    // concessionarias[0].adicionarCarro(Automovel("Volkswagen", 15000.00, "BBBBBBBBBB", Tempo(17, 3, 2018)));
    // concessionarias[0].adicionarCarro(Automovel("Ford", 18000.50, "CCCCCCCCCC", Tempo(31, 3, 2018)));
    // concessionarias[0].adicionarCarro(Automovel("Nissan", 50500.00, "DDDDDDDDDD", Tempo(28, 8, 2019)));
    // concessionarias[0].adicionarCarro(Automovel("Hyundai", 78800.00, "EEEEEEEEEE", Tempo(14, 7, 2019)));

    // concessionarias[1].adicionarCarro(Automovel("Chevrolet", 16500.00, "FFFFFFFFFF", Tempo(1, 9, 2019)));
    // concessionarias[1].adicionarCarro(Automovel("Kia", 32000.00, "GGGGGGGGGG", Tempo(17, 8, 2018)));
    // concessionarias[1].adicionarCarro(Automovel("Mercedes-Benz", 45900.50, "HHHHHHHHHH", Tempo(31, 7, 2019)));
    // concessionarias[1].adicionarCarro(Automovel("Renault", 69999.90, "IIIIIIIIII", Tempo(30, 6, 2019)));

    // concessionarias[2].adicionarCarro(Automovel("Audi", 3600.00, "JJJJJJJJJJ", Tempo(29, 8, 2019)));
    // concessionarias[2].adicionarCarro(Automovel("Peugeot", 7000.00, "KKKKKKKKKK", Tempo(17, 3, 2018)));
    // concessionarias[2].adicionarCarro(Automovel("BMW", 125400.50, "LLLLLLLLLL", Tempo(31, 3, 2017)));


    // concessionarias[0].adicionarCarro(Automovel("Fiat", 20000.00, "219301293", Tempo(2, 3, 2019)));
    // std::cout << concessionarias[0] << std::endl;
    // concessionarias[0].showCarros();


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