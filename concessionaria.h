#include <string>
#include <vector>
#include "automovel.h"

class Concessionaria {
    private:
        std::string nome;
        int cnpj;
        int qtd_estoque;
        std::vector<Automovel> carros;
    public:
        Concessionaria(std::string nome, int cnpj);
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
        void adicionarCarro( Automovel c );
        void showCarros();
        ~Concessionaria();
};