#include "tempo.h"
#include <iomanip>

class Automovel {
    private:
        std::string marca;
        float preco;
        std::string chassi;
        Tempo data_criacao;
    public:
        Automovel(std::string m, float p, std::string c, Tempo d);
        friend std::ostream& operator<< (std::ostream &o, Automovel const a);
        void setPreco(float value);
        float getPreco();
        int getQtdDias();
        ~Automovel();
};