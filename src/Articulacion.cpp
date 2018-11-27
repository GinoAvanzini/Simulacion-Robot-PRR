
#include "Articulacion.h"
#include "Conjunto.h"

Articulacion::Articulacion(int ID) : Conjunto (ID){

    this->setBasicSettings(ID);

}

Articulacion::Articulacion(int ID, Qt3DCore::QEntity * rootEntity, QUrl url)
    : Conjunto (ID, rootEntity, url){

    this->setBasicSettings(ID);

}

void Articulacion::setBasicSettings(int ID){
    this->setId(ID);
    this->setTipo("Articulacion");
    this->setPeso(250);
    this->setDescripcion("Articulacion que permite movimiento angular en el plano X-Y");
    this->velang_max = 1; //En rad/s
    this->velang_min = 0.1;
    this->setAngulo_max(90);
    this->setAngulo_min(-90);

}

Articulacion::~Articulacion() {
}


void Articulacion::setRotationAxis(QVector3D eje){
    this->rotation = eje;

    this->controlpieza->setRotationAxis(eje);
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

int Articulacion::getAngulo_max() const {
    return angulo_max;
}

void Articulacion::setAngulo_max(int angulo_max) {
    this->angulo_max = angulo_max;
}

int Articulacion::getAngulo_min() const {
    return angulo_min;
}

void Articulacion::setAngulo_min(int angulo_min) {
    this->angulo_min = angulo_min;
}

void Articulacion::agregarCoordfi(float _coordfi){
    this->coordfi.push_back(_coordfi);
}

float Articulacion::getCoordfi(int i){
    return this->coordfi[i];
}
