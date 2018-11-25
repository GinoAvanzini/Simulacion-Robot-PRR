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
    void getInstruccion(std::string instruc);
    void interprete();

    void agregarAnimacion(int ID, bool sentido, int velocidad, int avance);

private:
    std::list <QPropertyAnimation> animaciones;
    std::list <QParallelAnimationGroup> paralelo;
    QSequentialAnimationGroup * secuencia;

    BaseRobot * BRobot;

    std::queue<std::string> instrucciones;

};

#endif // CONTROLADOR_H
