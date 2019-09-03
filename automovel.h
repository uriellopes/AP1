#include "tempo.h"
#include <string>

class Automovel {
    private:
        std::string marca;
        float preco;
        int chassi;
        Tempo data_criacao;
    public:
        Automovel(std::string marca, float preco, int chassi, Tempo data(int d, int m, int a));
        friend std::ostream& operator<< (std::ostream &o, Automovel const a);
        ~Automovel();
};