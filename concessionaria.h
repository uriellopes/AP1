#include <string>
#include "automovel.h"

class Concessionaria {
    private:
        std::string nome;
        int cnpj;
        int qtd_estoque;
    public:
        Concessionaria(std::string nome, int cnpj);
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
        ~Concessionaria();
};