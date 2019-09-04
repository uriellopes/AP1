#include "tempo.h"

class Automovel {
    private:
        std::string marca;
        float preco;
        std::string chassi;
        Tempo data_criacao;
    public:
        Automovel(std::string m, float p, std::string c, Tempo d);
        friend std::ostream& operator<< (std::ostream &o, Automovel const a);
        ~Automovel();
};