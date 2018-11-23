
#include "BaseRobot.h"
#include "Conjunto.h"
#include "ActuadorLineal.h"
#include "Articulacion.h"
#include "Eslabon.h"
#include "EfectorFinal.h"

#include <iostream>
using std::endl;


void BaseRobot::inicio(Qt3DCore::QEntity * rootEntity){

    //Instancia las articulaciones y el actuador lineal




}

BaseRobot::BaseRobot(int ID, bool t, string ip) : Conjunto(ID) {
    this->setEstado(t);
    this->setIp_data(ip);
    this->setId(ID);
//    this->inicio();
    //Llamar a otra función para la interfaz por línea de comandos
}

BaseRobot::BaseRobot(int ID, bool t, string ip, Qt3DCore::QEntity * rootEntity, QUrl url)
    : Conjunto(rootEntity, url)
{
    this->setEstado(t);
    this->setIp_data(ip);
    this->setId(ID);
    this->inicio(rootEntity);
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
