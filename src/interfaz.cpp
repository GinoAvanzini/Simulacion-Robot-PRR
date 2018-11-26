
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

//    ui->widget->createWindowContainer(this->view);

//    ui->horizontalLayout->addWidget(ui->widget);
//    this->view->resize(1000, 500);
    ui->horizontalLayout->addWidget(this->container);

//    this->view->resize(800, 400);
//    this->container->resize(800,400);
    this->container->setMinimumWidth(1000);
    this->container->setMinimumHeight(1000*9/16);

    ui->verticalLayout->setAlignment(Qt::AlignCenter);
//    this->container->resize(1000, 500);
//    this->container->setLayout(new QHBoxLayout);

//    ui->horizontalLayout_4->addWidget(this->container);
//    ui->horizontalLayout_4->setAlignment(Qt::AlignLeft);




//    ui->horizontalLayout_3->addWidget(this->container);

//    ui->horizontalLayout->setAlignment(Qt::AlignLeft);


//    this->layout->addWidget(this->container);

//    this->layout->addWidget(ui->pushButton);

    this->rootEntity = new Qt3DCore::QEntity;
    this->view->setRootEntity(this->rootEntity);

    // Setup de la cámara y su controlador
    this->setCamera();


    /*
     *  CREACIÓN DEL CONTROLADOR
     */

    this->ControladorRender = new Controlador(this->rootEntity);



    ui->verticalLayout->setAlignment(Qt::AlignLeft);


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
    delete ui;
}

void interfaz::on_Encendido_clicked()
{
    this->ControladorRender->setEstadoBR(true);
    std::cout << "ON" << std::endl;
}
void interfaz::on_Apagado_clicked()
{
    this->ControladorRender->setEstadoBR(false);
    std::cout << "OFF" << std::endl;
}

void interfaz::on_Comenzar_clicked()
{
    if (this->ControladorRender->getEstadoBR()){
        /*
         * LEER ARCHIVO
         */

        this->leerArchivo();

    } else {
        std::cout << "Encienda el Robot" << std::endl;
    }
}

void interfaz::on_pushButton_2_clicked()
{
    return;
}
