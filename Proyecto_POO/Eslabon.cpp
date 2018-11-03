/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Eslabon.cpp
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:23
 */

#include "Eslabon.h"
#include "Conjunto.h"

Eslabon::Eslabon(int ID){ //eslabon brazo
    this->longitud = 300;
    this->setTipo("Eslabon brazo");
    this->setId(ID);
    this->setPeso(1500);
    this->setDescripcion("Eslabon de brazo de 300mm de largo.");

}

Eslabon::Eslabon(int longitud, int ID) { //eslabon columna
    this->longitud = longitud;
    this->setTipo("Eslabon columna");
    this->setId(ID);
    this->setPeso(4000);
    this->setDescripcion("Eslabon de columna de 400mm de alto");

}

Eslabon::Eslabon(const Eslabon& orig) {
}

Eslabon::~Eslabon() {
}
