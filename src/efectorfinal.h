#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

#include "Conjunto.h"


class EfectorFinal : public Conjunto
{
public:
    EfectorFinal(int ID);

    int getDuracionPintar() const;
    int getDuracionRotar() const;
    int getDuracionSoltar() const;
    int getDuracionSostener() const;


private:
    int duracionPintar;
    int duracionRotar;
    int duracionSoltar;
    int duracionSostener;

};

#endif // EFECTORFINAL_H
