/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "EfectorFinal.h"
#include <string>
#include <unistd.h>
#include <iostream>
#include <iomanip>
using namespace std;
 
EfectorFinal::EfectorFinal(bool _estado){
    this->setEstado(_estado);  
}

void EfectorFinal::iniciar(int i){
    switch (this->getAuxiliar(i)) {
            case 1:{
                this->pintar(this->getCiclos(i));
            }
            break;
            case 2:{   
                this->sostener(this->getCiclos(i));
            }
            break;
            case 3:{
                this->soltar(this->getCiclos(i));
            }
            break;
            case 4:{
                this->rotar(this->getCiclos(i));
            }
            break;
            case 5:{
                this->cambiarVelocidad(this->getCiclos(i));
            }
            break;
        }
    
    
}

void EfectorFinal::pintar(int i){
    for (int j=0; j<i; j++){
        usleep(500000);
        cout << "Estado: " << this->estado << setw(15) 
                << "PINTANDO: " << setw(25) << "Cant. ciclos a realizar: " 
                << i << setw(20) << "Ciclo actual: " << j+1 <<endl;
    }
}

void EfectorFinal::sostener(int i){
    for (int j=0; j<i; j++){
        usleep(500000);
        cout << "Estado: " << this->estado << setw(15) 
                << "Sosteniendo: " << setw(25) << "Cant. ciclos a realizar: " 
                << i << setw(20) << "Ciclo actual: " << j+1 <<endl;
    }
}

void EfectorFinal::soltar(int i){
    for (int j=0; j<i; j++){
        usleep(500000);
        cout << "Estado: " << this->estado << setw(15) 
                << "Soltando: " << setw(25) << "Cant. ciclos a realizar: " 
                << i << setw(20) << "Ciclo actual: " << j+1 <<endl;
    }
}

void EfectorFinal::rotar(int i){
    for (int j=0; j<i; j++){
        usleep(500000);
        cout << "Estado: " << this->estado << setw(15) 
                << "Rotando: " << setw(25) << "Cant. ciclos a realizar: " 
                << i << setw(20) << "Ciclo actual: " << j+1 <<endl;
    }
}

void EfectorFinal::cambiarVelocidad(int i){
    for (int j=0; j<i; j++){
        usleep(500000);
        cout << "Estado: " << this->estado << setw(15) 
                << "Cambiando velocidad: " << setw(25) << "Cant. ciclos a realizar: " 
                <<i<< setw(20) << "Ciclo actual: " << j+1 <<endl;
    }
}

void EfectorFinal::setEstado(bool _estado){
    this->estado=_estado;
}


 void EfectorFinal::agregar(int _tarea,int _ciclos){
        switch (_tarea) {
            case 1:{
                this->agregarTarea("PINTAR");
                this->agregarCiclo(_ciclos);
                this->agregarAuxiliar(_tarea);
            }
            break;
            case 2:{   
                this->agregarTarea("SOSTENER");
                this->agregarCiclo(_ciclos);
                this->agregarAuxiliar(_tarea);
            }
            break;
            case 3:{
                this->agregarTarea("SOLTAR");
                this->agregarCiclo(_ciclos);
                this->agregarAuxiliar(_tarea);
            }
            break;
            case 4:{
                this->agregarTarea("ROTAR");
                this->agregarCiclo(_ciclos);
                this->agregarAuxiliar(_tarea);
            }
            break;
            case 5:{
                this->agregarTarea("CAMBIAR VELOCIDAD");
                this->agregarCiclo(_ciclos);
                this->agregarAuxiliar(_tarea);
            }
            break;
        }
    }
 
 void EfectorFinal::agregarTarea(std::string tarea){
        this->accion.push_back(tarea);
     }
    
 void EfectorFinal::agregarCiclo(int _ciclos){
         this->ciclos.push_back(_ciclos);
     }
 
 void EfectorFinal::agregarAuxiliar(int _tarea){
         this->auxiliar.push_back(_tarea);
 }
 
 std::string EfectorFinal::getAccion(int i){
     return this->accion[i];
 }
 
 int EfectorFinal::getCiclos(int i){
     return this->ciclos[i];
 }
 
 int EfectorFinal::getAuxiliar(int i){
     return this->auxiliar[i];
 }