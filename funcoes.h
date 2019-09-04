#include "concessionaria.h"

void clear();
void pressToCont();
bool checkBissexto(int &ano);
bool validarData(int d, int m, int a);
void addInfo(std::vector<Concessionaria> &concessionarias);
void novaConcessionaria(std::vector<Concessionaria> &concessionarias);
void showMenu(std::vector<Concessionaria> &concessionarias);