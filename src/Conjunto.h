/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Conjunto.h
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:21
 */

#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
#include <string>
using std::string;


class Conjunto {
public:
    void inicio();
    Conjunto();
    Conjunto(const Conjunto& orig);
    virtual ~Conjunto();

    string getDescripcion() const;
    void setDescripcion(string descripcion);

    int getId() const;
    void setId(int id);

    int getPeso() const;
    void setPeso(int peso);

    string getTipo() const;
    void setTipo(string tipo);

private:
    int id;
    int peso;
    string descripcion;
    string tipo;

};

#endif /* CONJUNTO_H */
