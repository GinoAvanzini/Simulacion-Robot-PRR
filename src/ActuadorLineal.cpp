
#include "ActuadorLineal.h"
#include "Conjunto.h"

ActuadorLineal::ActuadorLineal(int ID) : Conjunto (ID) {
    this->setId(ID);
    this->setTipo("Actuador Lineal");
    this->setPeso(250);
    this->setDescripcion("Actuador que permite el movimiento en Z");
    this->veline_max = 50; //En mm/s
    this->veline_min = 0.5;
    this->distancia_max = 40;  //En mm
    this->distancia_min = 5;
}

ActuadorLineal::~ActuadorLineal() {
}

void ActuadorLineal::setVelActual(float velocidad){
    this->vel_actual = velocidad;
}

float ActuadorLineal::getVelActual() const{
    return this->vel_actual;
}

float ActuadorLineal::getVelLine_max() const{
    return this->veline_max;
}

float ActuadorLineal::getVelLine_min() const{
    return this->veline_min;
}


int ActuadorLineal::getDistancia_max() const {
        return distancia_max;
}

int ActuadorLineal::getDistancia_min() const {
        return distancia_min;
}

void ActuadorLineal::agregarCoordz(float _coordz){
         this->coordz.push_back(_coordz);
}

float ActuadorLineal::getCoordz(int i){
     return this->coordz[i];
}

