
#include "Conjunto.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;


Conjunto::Conjunto(int ID) : QObject() {
    this->setId(ID);
}

Conjunto::Conjunto(int ID, Qt3DCore::QEntity * rootEntity, QUrl url) : QObject(rootEntity){

    this->setId(ID);

    this->entity = new Qt3DCore::QEntity(rootEntity);
    this->mesh = new Qt3DRender::QMesh();
    this->mesh->setSource(url);

    this->setMaterial(rootEntity);

    this->transform = new Qt3DCore::QTransform;

    this->entity->addComponent(this->material);
    this->entity->addComponent(this->mesh);
    this->entity->addComponent(this->transform);

    //CONTROL DE LA PIEZA
    this->controlpieza = new Control(this->transform);
    this->controlpieza->setTarget(this->transform);



}

Conjunto::Conjunto(const Conjunto& orig) {
}

Conjunto::~Conjunto() {

    delete this->entity;
    delete this->mesh;
    delete this->material;
    delete this->controlpieza;
    delete this->transform;

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

Qt3DCore::QTransform * Conjunto::getTransform(){
    return this->transform;
}


