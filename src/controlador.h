#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <list>
#include <string>
#include <queue>

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>

#include "BaseRobot.h"



class Controlador
{
public:
    Controlador(Qt3DCore::QEntity * rootEntity);
    ~Controlador();
    void agregarInstruccion(std::string instruc);
    void interprete();

    void agregarAnimacion(int ID, bool sentido, int velocidad, int avance);
    void startAnimacion();

    bool getEstadoBR();
    void setEstadoBR(bool estado);


private:

    std::list <QPropertyAnimation * > animaciones;
    std::list <QParallelAnimationGroup * > paralelo;
    QSequentialAnimationGroup * secuencia;

    BaseRobot * BRobot;

    int alturaAbsoluta = 0;

    int ang1Absoluto = 0;

    std::queue<std::string> instrucciones;

};

#endif // CONTROLADOR_H
