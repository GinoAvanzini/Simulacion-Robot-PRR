#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QOrbitCameraController>

#include <Qt3DCore/QEntity>

#include <Qt3DRender/QCamera>
#include <Qt3DRender/QEnvironmentLight>
#include <Qt3DRender/QPointLight>

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

private slots:
    void on_Encendido_clicked();

    void on_pushButton_2_clicked();

    void on_Apagado_clicked();

    void on_Comenzar_clicked();

    void on_SALIR_clicked();

    void on_Descripcion_clicked();

private:

    Ui::interfaz *ui;

    Qt3DExtras::Qt3DWindow * view;
    QWidget * container;
    QVBoxLayout * layout;

    std::ifstream archivo;


    Qt3DCore::QEntity * rootEntity;

    Qt3DRender::QCamera * cameraEntity;
    Qt3DExtras::QOrbitCameraController * camController;
    Qt3DCore::QEntity * lightEntity;
    Qt3DRender::QPointLight * light;

    Controlador * ControladorRender;

};

#endif // INTERFAZ_H
