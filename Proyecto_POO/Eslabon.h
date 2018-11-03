/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Eslabon.h
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:23
 */

#ifndef ESLABON_H
#define ESLABON_H

#include "Conjunto.h"

class Eslabon : public Conjunto{
public:
    Eslabon(int ID); //eslabones brazo
    Eslabon(int long, int ID); //Eslabon columna
    Eslabon(const Eslabon& orig);
    virtual ~Eslabon();

private:
    int longitud;
};

#endif /* ESLABON_H */
