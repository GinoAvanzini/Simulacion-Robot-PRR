#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QOrbitCameraController>

#include <Qt3DCore/QEntity>

#include <Qt3DRender/QCamera>

#include <QVBoxLayout>

#include <iostream>
#include <fstream>

#include <QFile>

#include "BaseRobot.h"

#include "controlador.h"

namespace Ui {
class interfaz;
}

class interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit interfaz(QWidget *parent = nullptr);
    void setCamera();
    ~interfaz();
    void leerArchivo();

private:

    Ui::interfaz *ui;

    Qt3DExtras::Qt3DWindow * view;
    QWidget * container;
    QVBoxLayout * layout;

    std::ifstream archivo;


    Qt3DCore::QEntity * rootEntity;

    Qt3DRender::QCamera * cameraEntity;
    Qt3DExtras::QOrbitCameraController * camController;

    Controlador * ControladorRender;

};

#endif // INTERFAZ_H
