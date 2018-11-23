
#ifndef ESLABON_H
#define ESLABON_H

#include "Conjunto.h"

class Eslabon : public Conjunto{
public:
    Eslabon(int ID); //eslabones brazo
    Eslabon(int longitud, int ID); //Eslabon columna
    virtual ~Eslabon();

private:
    int longitud;
};

#endif /* ESLABON_H */
