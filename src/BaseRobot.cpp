
#include "BaseRobot.h"
#include "Conjunto.h"
#include "ActuadorLineal.h"
#include "Articulacion.h"
#include "Eslabon.h"
#include "EfectorFinal.h"

#include <iostream>
using std::endl;


void BaseRobot::inicio(){

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
