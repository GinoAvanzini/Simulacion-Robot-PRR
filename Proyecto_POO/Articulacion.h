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
#include <vector>
using std::string;
using std::vector;

class Articulacion : public Conjunto{
public:
    Articulacion(int ID,int amax, int amin);
    Articulacion(const Articulacion& orig);
    virtual ~Articulacion();
    void setVelActual(float velocidad);
    float getVelActual() const;
    float getVelAng_max() const;
    float getVelAng_min() const;
    int getAngulo_max() const;
    void setAngulo_max(int angulo_max);
    int getAngulo_min() const;
    void setAngulo_min(int angulo_min);
    void agregarCoordfi(float _coordfi);
    float getCoordfi(int i);


private:
    std::vector<float> coordfi;
    int angulo_max;
    int angulo_min;
    float vel_actual;   
    float velang_max;
    float velang_min;

};

#endif /* ARTICULACION_H */
