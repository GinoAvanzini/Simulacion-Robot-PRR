
#include "interfaz.h"
#include "ui_interfaz.h"

#include "controlador.h"



interfaz::interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interfaz)
{
    ui->setupUi(this);

    this->resize(this->maximumWidth(), this->maximumHeight());

    this->view = new Qt3DExtras::Qt3DWindow;
    this->container = QWidget::createWindowContainer(this->view);
    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->container);

//    this->layout->addWidget(ui->pushButton);

    this->rootEntity = new Qt3DCore::QEntity;
    this->view->setRootEntity(this->rootEntity);

    // Setup de la cámara y su controlador
    this->setCamera();


    /*
     *  CREACIÓN DEL CONTROLADOR
     */

    this->ControladorRender = new Controlador(this->rootEntity);




    /*
     * LEER ARCHIVO
     */

    this->leerArchivo();


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
