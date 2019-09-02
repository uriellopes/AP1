#include <string>
#include "automovel.h"

class Concessionaria {
    private:
        string nome;
        int cnpj;
        int qtd_estoque;
    public:
        Concessionaria(string nome, int cnpj);
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
        ~Concessionaria();
};