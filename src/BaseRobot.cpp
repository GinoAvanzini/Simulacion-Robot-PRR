
#include "BaseRobot.h"
#include "Conjunto.h"
#include "ActuadorLineal.h"
#include "Articulacion.h"

#include <iostream>
using std::endl;


void BaseRobot::inicio(Qt3DCore::QEntity * rootEntity){

    //Instancia las articulaciones y el actuador lineal

    {
        QUrl path = QStringLiteral("qrc:/res/actuador_lineal.obj");
        this->ActLineal = new ActuadorLineal(10, rootEntity, path);
    }

    {
        QUrl path = QStringLiteral("qrc:/res/articulacion1.obj");
        this->articulacion1 = new Articulacion(11, rootEntity, path);
    }

    {
        QUrl path = QStringLiteral("qrc:/res/articulacion2.obj");
        this->articulacion2 = new Articulacion(12, rootEntity, path);
    }

    this->EfectorF = new EfectorFinal(50);



//    this->articulacion2->transform->rotateAround(QVector3D(0, 0, 0), 45, QVector3D(0, 10, 0));



}

BaseRobot::BaseRobot(int ID, bool t, string ip) : Conjunto(ID) {
    this->setEstado(t);
    this->setIp_data(ip);

    //Llamar a otra función para la interfaz por línea de comandos

}

BaseRobot::BaseRobot(int ID, bool t, string ip, Qt3DCore::QEntity * rootEntity, QUrl url)
    : Conjunto(ID, rootEntity, url)
{

    this->setEstado(t);
    this->setIp_data(ip);

}


BaseRobot::~BaseRobot() {

    delete this->articulacion1;
    delete this->articulacion2;
    delete this->ActLineal;


}

bool BaseRobot::getEstado() const {
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
