
#include "interfaz.h"
#include "ui_interfaz.h"

#include "controlador.h"

#include <QStringLiteral>
#include <QString>

#include <QFileDialog>

#include <iostream>
#include <chrono>
#include <thread>



interfaz::interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interfaz)
{
    ui->setupUi(this);

    // Hacer resize a maximum me hace crashear el programa
//    this->resize(this->maximumWidth(), this->maximumHeight());
    this->resize(1400, 800);

    this->view = new Qt3DExtras::Qt3DWindow;
    this->container = QWidget::createWindowContainer(this->view);
    ui->horizontalLayout->addWidget(this->container);

    this->container->setMinimumWidth(1550);
    this->container->setMinimumHeight(1550*9/16);


    ui->verticalLayout->setAlignment(Qt::AlignCenter);

    ui->spinBox->setMinimum(-500);

    ui->spinBox->setMaximum(500);

    ui->spinBox_2->setMaximum(150);


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


    QString filename = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                "..",
                                                "All Files (*.*)"
                                                );

    QFile file(filename);

    if (file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();

            this->ControladorRender->agregarInstruccion(line.toStdString());

        }

        file.close();
    }

}

void interfaz::setCamera(){

    this->cameraEntity = this->view->camera();
    this->cameraEntity->lens()->setPerspectiveProjection(75.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    this->cameraEntity->setPosition(QVector3D(-15, 65, 85.0f));
//  this->cameraEntity->setPosition(QVector3D(10, 50, 80.0f));
//        this->cameraEntity->setPosition(QVector3D(0, 200.0f, 0));
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
    ui->textEdit->setPlainText("APAGADO");
}



void interfaz::on_cargarArchivo_clicked()
{
    if (this->ControladorRender->getEstadoBR()){

        /*
         * LEER ARCHIVO
         */
        this->leerArchivo();
        this->estadoInput = true;
        ui->textEdit->setPlainText("Archivo Cargado");

    } else {

        ui->textEdit->setPlainText("Encienda el Robot\n");

    }
}

void interfaz::on_Comenzar_clicked()
{
    if (this->ControladorRender->getEstadoBR() && this->estadoInput){
        this->ControladorRender->startAnimacion();
    } else if (!this->ControladorRender->getEstadoBR()){
        ui->textEdit->setPlainText("Encienda el Robot\n");
    } else if (!this->estadoInput) {
        ui->textEdit->setPlainText("Cargue el archivo\n");
    }
}

void interfaz::on_Descripcion_clicked()
{
    ui->textEdit_2->append("Robot PRR tipo Scara\n");
    ui->textEdit_2->append("Descripción de piezas\n");

    //No pude acceder a getDescripcion, getPeso por alguna razón, fijate si lo podes
    //solucionar. Por ahora lo hardcodeo

    ui->textEdit_2->append("- Actuador Lineal:\n");
    ui->textEdit_2->append("  Actuador que permite el movimiento en Z\n  Peso: 250\n");

    ui->textEdit_2->append("- Articulacion:\n");
    ui->textEdit_2->append("  Articulacion que permite movimiento angular en el plano X-Y\n  Peso: 250");

    ui->textEdit_2->append("\n\nDesarrollado con herramientas Open Source"
                           " por Gino Hernán Avanzini"
                           " y Emiliano Martín Cabrino.\n\n"
                           "Programación Orientada a Objetos. Facultad de Ingeniería. "
                           "Universidad Nacional de Cuyo.\n\nAño 2018");


    //    ui->textEdit_2->append();
    return;

}


void interfaz::on_SALIR_clicked()
{
    this->~interfaz();
}



void interfaz::on_borrarSecuencia_clicked()
{
    this->ControladorRender->borrarSecuencia();

    this->ControladorRender->realizarHoming();

    this->ControladorRender->startAnimacion();


    ui->textEdit->setPlainText("Para borrar también la secuencia de homing "
                               "debe presionar el botón de borrar secuencia"
                               "una vez termina la simulación de la vuelta"
                               "al origen.\n"
                               "Secuencia borrada. \n"
                               "Puede ingresar nuevas instrucciones");


    /* ATENCION
     *
     * FALTA IMPLEMENTACIÓN!!!
     *
     * Para poder borrar la secuencia que hay almacenada y que a la vez se vea
     * bien la transición hago una borrarSecuencia y un homing. Pero luego hay
     * que borrar dicho homing. Si ejecuto un borrarSecuencia inmediatamente
     * vuelve todo al origen abruptamente.
     *
     * Una opción sería recurrir a threads. Crear uno que tome el tiempo que
     * tarda en terminar la animación del homing y recién ahí realizar el
     * borrado de la secuencia. Mientras tanto, el proceso del programa
     * principal sigue funcionando normalmente. Probablemente haya problemas
     * igual.
     *
     * -------------------------------------------------------------------------
     * Otra opción sería tomar la signal de fin de animación y conectarla con
     * un slot que borre la animación. Este slot se ejecuta si está levantada
     * una bandera que se levanta en on_borrarSecuencia_clicked. Luego de
     * borrar la animación en el slot se baja la bandera nuevamente.
     * -------------------------------------------------------------------------
     *
     */


}




void interfaz::on_agregarMovimiento_clicked()
{

    this->estadoInput = true;

    QString actuador;

    int avance;

    actuador.append('G');

    if (ui->comboBox->currentIndex() == 0){
        actuador.append('1');
    }
    else if (ui->comboBox->currentIndex() == 1) {
        actuador.append('2');
    }
    else if (ui->comboBox->currentIndex() == 2) {
        actuador.append('3');
    }

    if (ui->spinBox->value() <= 0) {
        actuador.append('2');

        avance = -ui->spinBox->value();
    } else {
        actuador.append('1');
        avance = ui->spinBox->value();
    }

    this->ControladorRender->agregarInstruccion(actuador.toStdString());

    this->ControladorRender->agregarInstruccion(std::to_string(ui->spinBox_2->value()));

    this->ControladorRender->agregarInstruccion(std::to_string(avance));

    this->ControladorRender->agregarInstruccion("C00");



}
