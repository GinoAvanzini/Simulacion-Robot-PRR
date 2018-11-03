/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ActuadorLineal.h
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 19:50
 */

#ifndef ACTUADORLINEAL_H
#define ACTUADORLINEAL_H

#include "Conjunto.h"
#include <string>
using std::string;

class ActuadorLineal : public Conjunto{
public:
    ActuadorLineal(int ID);
    ActuadorLineal(const ActuadorLineal& orig);
    virtual ~ActuadorLineal();

    void setVelActual(float velocidad);
    float getVelActual() const;

    float getVelLine_max() const;
    float getVelLine_min() const;
private:
  float vel_actual;
  float veline_max;
  float veline_min;

};

#endif /* ACTUADORLINEAL_H */
