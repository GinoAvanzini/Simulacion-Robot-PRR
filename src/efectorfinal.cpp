#include "efectorfinal.h"

EfectorFinal::EfectorFinal(int ID) : Conjunto(ID)
{

    this->duracionPintar = 1000;
    this->duracionRotar = 500;
    this->duracionSoltar = 200;
    this->duracionSostener = 1200;

}

int EfectorFinal::getDuracionPintar() const {
    return this->duracionPintar;
}

int EfectorFinal::getDuracionSoltar() const {
    return this->duracionSoltar;
}

int EfectorFinal::getDuracionSostener() const {
    return this->duracionSostener;
}

int EfectorFinal::getDuracionRotar() const {
    return this->duracionRotar;
}
