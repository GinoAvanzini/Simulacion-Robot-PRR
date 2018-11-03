/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Articulacion.h
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:22
 */

#ifndef ARTICULACION_H
#define ARTICULACION_H

#include "Conjunto.h"
#include <string>
using std::string;

class Articulacion : public Conjunto{
public:
    Articulacion(int ID);
    Articulacion(const Articulacion& orig);
    virtual ~Articulacion();

    void setVelActual(float velocidad);
    float getVelActual() const;

    float getVelAng_max() const;
    float getVelAng_min() const;

private:
    //array coord_actual;
    // int angulo_max;
    // int angulo_min;
    float vel_actual;

    //Velocidades angulares mínimas y máximas
    float velang_max;
    float velang_min;

};

#endif /* ARTICULACION_H */
