/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EfectorFinal.h
 * Author: emiliano
 *
 * Created on 30 de septiembre de 2018, 17:00
 */

#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

#include "Conjunto.h"
#include <vector>
#include <string>
using namespace std;


class EfectorFinal : public Conjunto{
private:
    bool estado;
    int velocidad;
    std::vector<std::string> accion;
    std::vector<int> ciclos;
    std::vector<int> auxiliar;
public:
    EfectorFinal(bool _estado);
    virtual ~EfectorFinal();
   // void informarCiclos();
    void pintar(int i);
    void rotar(int i);
    void soltar(int i);
    void cambiarVelocidad(int i);
    void sostener(int i);
    void agregar(int _accion, int _ciclos);
    void agregarTarea(std::string _tarea);
    void agregarCiclo(int _ciclos);
    void agregarAuxiliar(int _accion);
    void setVelocidad(int _velocidad);
    void iniciar(int i);
    void setEstado(bool _estado);
    int getAuxiliar(int i);
    int getCiclos(int i);
    int getVelocidad();
    bool isEstado();
    std::string getAccion(int i);
};

#endif /* EFECTORFINAL_H */
