
#include "interfaz.h"
#include "ui_interfaz.h"

#include "controlador.h"

#include <iostream>



interfaz::interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interfaz)
{
    ui->setupUi(this);

//    this->resize(this->maximumWidth(), this->maximumHeight());

    this->view = new Qt3DExtras::Qt3DWindow;
    this->container = QWidget::createWindowContainer(this->view);
    ui->horizontalLayout->addWidget(this->container);

    this->container->setMinimumWidth(1000);
    this->container->setMinimumHeight(1000*9/16);

    ui->verticalLayout->setAlignment(Qt::AlignCenter);


    this->rootEntity = new Qt3DCore::QEntity;
    this->view->setRootEntity(this->rootEntity);

    // Setup de la cámara y su controlador
    this->setCamera();

    // Setup de la luz
    this->lightEntity = new Qt3DCore::QEntity(this->rootEntity);
    this->light = new Qt3DRender::QPointLight(this->lightEntity);
    this->light->setColor("white");
    this->light->setIntensity(1);
    this->lightEntity->addComponent(this->light);
    Qt3DCore::QTransform * lightTransform = new Qt3DCore::QTransform(this->lightEntity);
    lightTransform->setTranslation(QVector3D(150, 150, 0));
    this->lightEntity->addComponent(lightTransform);


    /*
     *  CREACIÓN DEL CONTROLADOR
     */

    this->ControladorRender = new Controlador(this->rootEntity);


    //-----------------------------------------------

    this->view->setRootEntity(this->rootEntity);

    //-----------------------------------------------

}


void interfaz::leerArchivo(){

//    this->archivo.open(":/res/GCode.txt");


    // ARREGLAR PATH DEL ARCHIVO
    this->archivo.open("/home/gino/Dropbox/FING/Programación_Orientada_a_Objetos/TP-Integrador_POO/res/GCode.txt");

    std::string linea;

    while(getline(this->archivo, linea)){

        this->ControladorRender->agregarInstruccion(linea);

        std::cout << linea << std::endl;

    }


}

void interfaz::setCamera(){

    this->cameraEntity = this->view->camera();
    this->cameraEntity->lens()->setPerspectiveProjection(75.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    this->cameraEntity->setPosition(QVector3D(10, 50, 80.0f));
    this->cameraEntity->setViewCenter(QVector3D(0, 0, 0));
    this->cameraEntity->setUpVector(QVector3D(0, 1, 0));

    this->camController = new Qt3DExtras::QOrbitCameraController(this->rootEntity);
    this->camController->setLinearSpeed(50.0f);
    this->camController->setLookSpeed(180.0f);
    this->camController->setCamera(this->cameraEntity);

}

interfaz::~interfaz()
{

    delete this->view;
    delete this->container;
    delete this->layout;
    delete this->rootEntity;
    delete this->cameraEntity;

    delete this->camController;
    delete this->light;
    delete this->lightEntity;

    delete this->ControladorRender;

    delete this->ui;



}

void interfaz::on_Encendido_clicked()
{
    this->ControladorRender->setEstadoBR(true);
    ui->textEdit->setPlainText("ENCENDIDO");
}
void interfaz::on_Apagado_clicked()
{
    this->ControladorRender->setEstadoBR(false);
//    std::cout << "OFF" << std::endl;
    ui->textEdit->setPlainText("APAGADO");}

void interfaz::on_Comenzar_clicked()
{
    if (this->ControladorRender->getEstadoBR()){

        /*
         * LEER ARCHIVO
         */
        this->leerArchivo();

    } else {

        ui->textEdit->setPlainText("Encienda el Robot\n");

    }
}

void interfaz::on_pushButton_2_clicked()
{
    return;
}

void interfaz::on_SALIR_clicked()
{
    this->~interfaz();
}
