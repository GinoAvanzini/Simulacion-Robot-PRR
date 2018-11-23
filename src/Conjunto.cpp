
#include "Conjunto.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;


Conjunto::Conjunto() : QObject() {
}

Conjunto::Conjunto(const Conjunto& orig) {
}

Conjunto::~Conjunto() {
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
