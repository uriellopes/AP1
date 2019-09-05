#include <iostream>
#include "funcoes.h"

#ifdef _WIN32
#define LIMPAR "CLS"
#elif
#define LIMPAR "clear"
#endif

//Funcao para limpar a tela
void clear() {
    system(LIMPAR);
}

//Funcao para pressionar enter para continuar
void pressToCont() {
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore();
    std::cin.ignore();
}

//Funcao para chegar se o input é um int
bool checarDigito(std::string &input) {
    for (unsigned int  i = 0; i < input.size(); i++) {
        if( !isdigit(input[i]) ) {
            return false;
            break;
        }
    }
    return true;
}

//Funcao para chegar se o input é um float
bool checarFloat(std::string &input) {
    int ponto = 0;
    for (unsigned int  i = 0; i < input.size(); i++) {
        if( !isdigit(input[i]) ) {
            if( input[i] != '.') {
                return false;
            } else {
                ponto++;
            }
        }
    }

    if( ponto < 2 ) {
        return true;
    } else {
        return false;
    }
}

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
    concessionarias.push_back(Concessionaria("Concessionaria 1", 321997547555590));
    concessionarias.push_back(Concessionaria("Concessionaria 2", 479378124000401));
    concessionarias.push_back(Concessionaria("Concessionaria 3", 122312123444407));

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

//Funcao para criar uma nova concessionaria
void novaConcessionaria(std::vector<Concessionaria> &concessionarias) {
    clear();
    std::string nome;
    std::string input;
    long long int cnpj;
    bool existe = false;
    bool inputValido;

    std::cout << std::endl << "#######################################" << std::endl;
    std::cout << "##   1 - Criar nova concessionaria   ##" << std::endl;
    std::cout << "#######################################" << std::endl << std::endl;

    std::cout << "Digite o nome da nova concessionaria: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    do {
        inputValido = true;
        std::cout << "Digite o CNPJ da nova concessionaria ( Digite apenas os numeros ): ";
        std::cin >> input;

        inputValido = checarDigito(input);

        if( !inputValido ) {
            std::cout << std::endl;
            std::cout << "Digite apenas numeros para um valor valido!!" << std::endl;
        }        

    } while ( !inputValido );

    cnpj = stoll(input, nullptr, 10);

    for(unsigned int i = 0; i < concessionarias.size(); i++ ) {
        if( concessionarias[i].getCNPJ() == cnpj || nome.compare(concessionarias[i].getNome()) == 0 ) {
            existe = true;
            break;
        }
    }

    if( existe ) {
        std::cout << std::endl;
        std::cout << "==============================================================" << std::endl;
        std::cout << "Ja existe uma concessionaria cadastrada com esse nome ou cnpj!" << std::endl;
        std::cout << "==============================================================" << std::endl << std::endl;
    } else {
        concessionarias.push_back(Concessionaria(nome, cnpj));
        std::cout << std::endl;
        std::cout << "Concessionaria " << nome << " criada!" << std::endl;
        std::cout << std::endl;
    }

    pressToCont();
}

//Funcao que mostra o meno e recebe o valor para aumentar o preco dos carros de uma concessionaria
void menuAumentarPreco(Concessionaria &c) {
    bool inputValido;
    float valor;
    std::string input;

    clear();
    std::cout << "####################################################" << std::endl;
    std::cout << "##   3 - Aumentar preco de todos os carros em %   ##" << std::endl;
    std::cout << "####################################################" << std::endl << std::endl;

    do {
        inputValido = true;
        std::cout << "Digite o valor da % desejado ( Digite apenas os numeros e com apenas um '.' para separar o decimal ): ";
        std::cin >> input;

        inputValido = checarFloat(input);

        if( !inputValido ) {
            std::cout << std::endl;
            std::cout << "Digite apenas numeros float para um valor valido!!" << std::endl;
        }        

    } while ( !inputValido );

    valor = std::stof( input );

    c.aumentarPreco(valor);

    std::cout << "Preco de todos os carros aumentado em: " << valor << "%" << std::endl;

    pressToCont();
}

//Funcao para selecionar uma concessionaria
void selecionarConcessionaria(Concessionaria &c) {
    std::string input;
    int escolha;
    bool sair = false;
    bool error = false;
    do {
        clear();
        std::cout << std::endl << "###################################" << std::endl;
        std::cout <<  c;
        std::cout << "###################################" << std::endl << std::endl;

        std::cout << "Escolha uma das seguintes opcoes: " << std::endl << std::endl;

        std::cout << "[1] - Adicionar novo carro" << std::endl;
        std::cout << "[2] - Listar carros cadastrados" << std::endl;
        std::cout << "[3] - Aumentar preco de todos os carros em %" << std::endl;
        std::cout << "[4] - Listar carros produzidos ha menos de 90 dias" << std::endl;
        std::cout << std::endl;
        std::cout << "[0] - Sair" << std::endl;

        std::cout << std::endl;
        if ( error ) {
            error = false;
            std::cout << "**Digite uma opcao valida!**" << std::endl;
        }
        std::cout << "Opcao: ";
        std::cin >> input;

        if( checarDigito(input)) {
            escolha = std::stoi (input, nullptr);

            switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    break;
                case 2:
                    clear();
                    c.showCarros();
                    pressToCont();
                    break;
                case 3:
                    menuAumentarPreco(c);
                    break;
                case 4:
                    clear();
                    c.listarCarrosRecentes();
                    pressToCont();
                    break;
                default:
                    error = true;
                    break;
            }

        } else {
            error = true;
        }
    } while (!sair);
}

//Funcao que mostra o menu principal do codigo
void showMenu(std::vector<Concessionaria> &concessionarias) {
    std::string input;
    int escolha;
    bool sair = false;
    bool error = false;

    do {
        clear();
        std::cout << std::endl << "############################################################" << std::endl;
        std::cout << "###                      BEM VINDO!!                     ###" << std::endl;
        std::cout << "############################################################" << std::endl;
        std::cout << std::endl << "Escolha uma das seguintes opcoes: " << std::endl << std::endl;
        std::cout << "[1] - Criar nova Concessionaria" << std::endl;
        int opcoes = 1;
        for(unsigned int i = 0; i < concessionarias.size(); i++ ) {
            std::cout << "[" << i + 2 << "] - Selecionar Concessionaria " << concessionarias[i].getNome() << std::endl;
            opcoes++;
        }

        std::cout << std::endl;
        std::cout << "[0] - Sair" << std::endl << std::endl;

        if ( error ) {
            error = false;
            std::cout <<"**Digite uma opcao valida!**" << std::endl;
        }
        std::cout << "Opcao: ";
        std::cin >> input;

        if( checarDigito(input)) {
            escolha = std::stoi (input, nullptr);

            if( escolha >= 0 && escolha <= opcoes ) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    novaConcessionaria(concessionarias);
                    break;
                default:
                    selecionarConcessionaria(concessionarias[escolha - 2]);
                    break;
                }
            } else {
                error = true;
            }   
        } else {
            error = true;
        }
    } while( !sair );
}