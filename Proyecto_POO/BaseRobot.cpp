/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BaseRobot.cpp
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:21
 */

#include "BaseRobot.h"
#include "Conjunto.h"
#include "ActuadorLineal.h"
#include "Articulacion.h"
#include "Eslabon.h"
#include "EfectorFinal.h"
#include <iostream>
using std::endl;

void BaseRobot::inicio(){
  Eslabon *eslabon1;
  eslabon1 = new Eslabon(20, 400);

  Eslabon *eslabon2;
  eslabon2 = new Eslabon(21);

  Eslabon *eslabon3;
  eslabon3 = new Eslabon(22);

  Articulacion *articulacion1;
  articulacion1 = new Articulacion(10,90,-90);

  Articulacion *articulacion2;
  articulacion2 = new Articulacion(11,150,-150);

  ActuadorLineal *actuadorlineal1;
  actuadorlineal1 = new ActuadorLineal(15);

  EfectorFinal *efector1;
  efector1 = new EfectorFinal(1);

  int tarea = 0;
	bool estado = 0;
	int ciclos = 0;
	bool flag1 = true;
  bool flag2;
  int cont = 0;
  int encendido = 0;
  int i = 0, velocidad = 2;
  float fi1 = 0, fi2 = 0;


        while(flag1 == true){
            
            cout << "Ingrese:\n"
                << "0 para apagar\n"
                << "1 para mostrar identificacion\n"
                << "2 para mostrar descripcion\n"
                << "3 para mostrar peso\n"
                << "4 para cargar tareas\n"
                << "5 para cargar coordenadas\n"    
                << "6 para iniciar"<<endl;
            cin >> encendido;
            switch(encendido){
                case 1:
                {
                    this->getId();
                    break;
                }

                case 2:
                {
                    this->getDescripcion();
                    break;
                }

                case 3:
                {
                    this->getPeso();
                    break;
                }

                case 4:
                {

                    while(flag2 == true){
                        cout << "Ingrese:"<<endl
                            << "0 para volver al menu anterior\n"
                            << "1 para PINTAR\n"
                            << "2 para SOSTENER\n"
                            << "3 para SOLTAR\n"
                            << "4 para ROTAR\n"
                            << "5 para CAMBIAR VELOCIDAD"<<endl;
                        cin >> tarea;

                        if(tarea != 0){
                            if(tarea != 5){
                                cout << "Indique la cantidad de ciclos que dura dicha tarea:"<<endl;
                                cin >> ciclos;
                                efector1->agregar(tarea,ciclos);
                                cont++;
                            }
                            else {
                                cin >> ciclos;
                                cout << endl;
                                cout << "Indique la nueva velocidad:"<<endl;
                                efector1->agregar(tarea,ciclos);
                                cont++;
                                cout << "Indique la cantidad de ciclos que dura dicha tarea:"<<endl;
                            }
                        }
                        else{
                            flag2 = false;
                        }
                        

                    }
                    flag2=true;
                    break;
                }
                case 5:
                {
                    cout<<"indique el nuevo angulo de posicion del\n"
                        <<"primer eslabon de la cadena"<<endl;
                    cin>>articulacion1->agregarCoordfi(fi1);
                    cout<<"indique el nuevo angulo de posicion del\n"
                        <<"ultimo eslabon de la cadena"<<endl;
                    cin>>articulacion2->agregarCoordfi(fi2);
                    break;
                }
                case 6:
                {
                  for(i = 0; i < cont; i++){
                        efector1->iniciar(i);
                    }
                  break;
                }
                default:
                    flag1 = false;
                    break;
            }
        }
}

BaseRobot::BaseRobot(int ID, bool t, string ip) {
    this->setEstado(t);
    this->setIp_data(ip);
    this->setId(ID);
    this->inicio();
}

BaseRobot::BaseRobot(const BaseRobot& orig) {
}

BaseRobot::~BaseRobot() {
}

bool BaseRobot::isEstado() const {
         return estado;
}

void BaseRobot::setEstado(bool estado) {
         this->estado = estado;
}

string BaseRobot::getIp_data() const {
           return ip_data;
}

void BaseRobot::setIp_data(string ip_data) {
         this->ip_data = ip_data;
}
