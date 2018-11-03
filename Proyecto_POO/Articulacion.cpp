/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Articulacion.cpp
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:22
 */

#include "Articulacion.h"
#include "Conjunto.h"

Articulacion::Articulacion(int ID) {
    this->setId(ID);
    this->setTipo("Articulacion");
    this->setPeso(250);
    this->setDescripcion("Articulacion que permite movimiento angular en el plano X-Y");

    this->velang_max = 1; //En rad/s
    this->velang_min = 0.1;
}

Articulacion::Articulacion(const Articulacion& orig) {
}

Articulacion::~Articulacion() {
}



void Articulacion::setVelActual(float velocidad){
    this->vel_actual = velocidad;
}

float Articulacion::getVelActual() const{
    return this->vel_actual;
}

float Articulacion::getVelAng_max() const{
    return this->velang_max;
}

float Articulacion::getVelAng_min() const{
    return this->velang_min;
}
