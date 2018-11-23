
#include "Conjunto.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;


Conjunto::Conjunto() : QObject() {
}

Conjunto::Conjunto(Qt3DCore::QEntity * rootEntity, QUrl url){

    this->entity = new Qt3DCore::QEntity(rootEntity);
    this->mesh = new Qt3DRender::QMesh();
    this->mesh->setSource(url);

    this->setMaterial(rootEntity);

    this->transform = new Qt3DCore::QTransform();

}

Conjunto::Conjunto(const Conjunto& orig) {
}

Conjunto::~Conjunto() {
}

void Conjunto::setMaterial(Qt3DCore::QEntity * rootEntity){
    this->material = new Qt3DExtras::QPhongMaterial(rootEntity);
    this->material->setDiffuse(QColor(QRgb(0x787878)));
    this->material->setAmbient(QColor(QRgb(0x5B5B6A)));
}


string Conjunto::getTipo() const {
    return tipo;
}
void Conjunto::setTipo(string tipo) {
    this->tipo = tipo;
}


int Conjunto::getId() const {
    return id;
}
void Conjunto::setId(int id) {
    this->id = id;
}

string Conjunto::getDescripcion() const {
    return descripcion;
}
void Conjunto::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Conjunto::setPeso(int peso) {
    this->peso = peso;
}
int Conjunto::getPeso() const {
    return peso;
}
