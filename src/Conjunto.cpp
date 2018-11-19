/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Conjunto.cpp
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:21
 */

#include "Conjunto.h"
#include <iostream>

using std::cin;
using std::cout;
using std::string;


Conjunto::Conjunto() {
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
