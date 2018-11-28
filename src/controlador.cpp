#include "controlador.h"

#include <Qt3DExtras/QPlaneMesh>

#include <stdlib.h>

Controlador::Controlador(Qt3DCore::QEntity * rootEntity)
{

    //Render de Base Robot y las articulaciones
    {
        QUrl path = QStringLiteral("qrc:/res/base_robot.obj");
        this->BRobot = new BaseRobot(0, false, "192.168.1.10", rootEntity, path);
    }

    Qt3DCore::QEntity * floor = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QPlaneMesh * floorMesh = new Qt3DExtras::QPlaneMesh();
    Qt3DCore::QTransform * floorTransform = new Qt3DCore::QTransform();
    floorTransform->setScale(100);
    floorTransform->setTranslation(QVector3D(0, -10, 0));
    Qt3DExtras::QPhongMaterial * floorMat = new Qt3DExtras::QPhongMaterial();
    floorMat->setDiffuse((QColor(QRgb(0x9db1f0))));
    floor->addComponent(floorMat);
    floor->addComponent(floorMesh);
    floor->addComponent(floorTransform);



    this->BRobot->inicio(rootEntity);

    // Vector auxiliar que contiene el punto de rotacion del segundo brazo
    // Se inicializa en la posicion inicial de la articulacion (40, 0, 0)
    this->BRobot->articulacion2->setRotationAxis(this->rotationAxis);


    // Instancio contenedor con la animacion
    this->secuencia = new QSequentialAnimationGroup();


}

void Controlador::agregarInstruccion(std::string instruc){
    this->instrucciones.push(instruc);
    if (instruc == "C00"){
        this->interprete();
    }
}

void Controlador::interprete(){

    int ID = 0;
    bool sentido = true;
    int velocidad = 0;
    int avance = 0;  //Inicialización con valores nulos

    bool flag = true;

    std::string aux;
    while(!this->instrucciones.empty()){
        aux = this->instrucciones.front();
        this->instrucciones.pop();
        if(aux.front() == 'G'){
            aux.erase(0, 1);
            if (aux.front() == '1'){ //actuador lineal
                aux.erase(0, 1);
                ID = 10;
            }
            else if (aux.front() == '2') { //Primera articulacion
                aux.erase(0, 1);
                ID = 11;
            }
            else if (aux.front() == '3') {  // Segunda articulacion
                aux.erase(0, 1);
                ID = 12;
            }

            //            Implementación de homing de altura G50
            else if (aux.front() == '5'){
                aux.erase(0, 2);

                this->realizarHoming();
                continue;
            }

            if (aux.front() == '1' && flag){
                sentido = true;
            }
            else if (aux.front() == '2' && flag) {
                sentido = false;
            }

            if (flag) { // Si es G50 no entra acá
                aux = this->instrucciones.front();
                this->instrucciones.pop();
                velocidad = std::stoi(aux, nullptr, 10);
                aux = this->instrucciones.front();
                this->instrucciones.pop();
                avance = std::stoi(aux, nullptr, 10);
            }

            this->agregarAnimacion(ID, sentido, velocidad, avance);

        }
        else if (aux.front() == 'C') {
            /*
             * Deprecated part of the code. Used to this->startAnimacion, now
             * this is done with a button on the interface. Kept for clarity
             * reasons.
             */
            aux.erase(0, 3);
            continue;
        }
        else if (aux.front() == 'H') {
            aux.erase(0, 1);
            if (aux.front() == '1'){
                aux.erase(0, 1);
                ID = 1;
            }
            else if (aux.front() == '2') {
                aux.erase(0, 1);
                ID = 2;
            }
            else if (aux.front() == '3') {
                aux.erase(0, 1);
                ID = 3;
            }
            else if (aux.front() == '4') {
                aux.erase(0, 1);
                ID = 4;
            }

            aux = this->instrucciones.front();
            this->instrucciones.pop();
            int ciclos = std::stoi(aux, nullptr, 10);

            this->agregarAnimacion(ID, ciclos);

        }
    }


}

void Controlador::realizarHoming(){

    if (this->alturaAbsoluta >= 0) {
        this->agregarAnimacion(10, false, 50, this->alturaAbsoluta);
    } else {
        this->agregarAnimacion(10, true, 50, -this->alturaAbsoluta);
    }


    /* Normaliza el ángulo entre (-360, 360). También habría que implementarlo
     * al hacer el envío de los ángulos para la transformaciones si es que
     * no se limita el ángulo hasta el cual puede rotar el brazo
     */
    if (this->ang1Absoluto > 360 || this->ang1Absoluto < -360){
        this->ang1Absoluto = this->ang1Absoluto % 360;
    }
    // Optimiza el ángulo de regreso para homing
    if (this->ang1Absoluto < -180) {
        this->ang1Absoluto += 360;
    } else if (this->ang1Absoluto > 180) {
        this->ang1Absoluto -= 360;
    }
    /* No debería ser necesario hacerlo para el segundo ángulo ya que no está
     * pensado que dé una vuelta completa sobre ese eje. Limitación mecánica
     */


    if (this->ang1Absoluto >= 0) {
        this->agregarAnimacion(11, false, 75, this->ang1Absoluto);
    } else {
        this->agregarAnimacion(11, true, 75, -this->ang1Absoluto);
    }

    if (this->ang2Absoluto >= 0){
        this->agregarAnimacion(12, false, 90, this->ang2Absoluto);
    } else {
        this->agregarAnimacion(12, true, 90, -this->ang2Absoluto);
    }
}

//Sobrecarga de método para simular actuación del Efector Final
void Controlador::agregarAnimacion(int ID, int ciclos){

    int duracion;
    switch(ID){
    case 1:
        duracion = this->BRobot->EfectorF->getDuracionPintar();
        this->secuencia->addPause(duracion*ciclos);
        break;

    case 2:
        duracion = this->BRobot->EfectorF->getDuracionRotar();
        this->secuencia->addPause(duracion*ciclos);
        break;

    case 3:
        duracion = this->BRobot->EfectorF->getDuracionSoltar();
        this->secuencia->addPause(duracion*ciclos);
        break;

    case 4:
        duracion = this->BRobot->EfectorF->getDuracionSostener();
        this->secuencia->addPause(duracion*ciclos);
        break;
    }
}

void Controlador::agregarAnimacion(int ID, bool sentido, int velocidad, int avance){

    int signo;

    if (sentido == true){
        signo = 1;
    } else {
        signo = -1;
    }

    switch(ID){

    case 10:  //Actuador Lineal

        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->ActLineal->getTransform()));


        this->paralelo.push_front(new QParallelAnimationGroup());

        this->animaciones.front()->setTargetObject(this->BRobot->ActLineal->controlpieza);
        this->animaciones.front()->setPropertyName("altura");
        this->animaciones.front()->setStartValue(QVariant::fromValue(this->alturaAbsoluta));
        this->animaciones.front()->setEndValue(QVariant::fromValue(this->alturaAbsoluta + signo*avance));
        this->animaciones.front()->setDuration(1000*avance/velocidad);

        this->paralelo.front()->addAnimation(this->animaciones.front());


        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->articulacion1->getTransform()));

        this->animaciones.front()->setTargetObject(this->BRobot->articulacion1->controlpieza);
        this->animaciones.front()->setPropertyName("altura");
        this->animaciones.front()->setStartValue(QVariant::fromValue(this->alturaAbsoluta));
        this->animaciones.front()->setEndValue(QVariant::fromValue(this->alturaAbsoluta + signo*avance));
        this->animaciones.front()->setDuration(1000*avance/velocidad);

        this->paralelo.front()->addAnimation(this->animaciones.front());


        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->articulacion2->getTransform()));

        this->animaciones.front()->setTargetObject(this->BRobot->articulacion2->controlpieza);
        this->animaciones.front()->setPropertyName("altura");
        this->animaciones.front()->setStartValue(QVariant::fromValue(this->alturaAbsoluta));
        this->animaciones.front()->setEndValue(QVariant::fromValue(this->alturaAbsoluta + signo*avance));
        this->animaciones.front()->setDuration(1000*avance/velocidad);

        this->paralelo.front()->addAnimation(this->animaciones.front());


        this->alturaAbsoluta += signo*avance;

        this->secuencia->addAnimation(this->paralelo.front());

        break;


    case 11: // Primera articulación. Mueve ambos brazos con movimiento rotacional

        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->articulacion1->getTransform()));
        this->paralelo.push_front(new QParallelAnimationGroup());

        this->animaciones.front()->setTargetObject(this->BRobot->articulacion1->controlpieza);

        this->animaciones.front()->setPropertyName("angle");
        this->animaciones.front()->setStartValue(QVariant::fromValue(this->ang1Absoluto));
        this->animaciones.front()->setEndValue(QVariant::fromValue(this->ang1Absoluto + signo*avance));
        this->animaciones.front()->setDuration(1000*avance/velocidad);

        this->paralelo.front()->addAnimation(this->animaciones.front());



        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->articulacion2->getTransform()));

        this->animaciones.front()->setTargetObject((this->BRobot->articulacion2->controlpieza));

        this->animaciones.front()->setPropertyName("angle3");
        this->animaciones.front()->setStartValue(QVariant::fromValue(this->ang1Absoluto));
        this->animaciones.front()->setEndValue(QVariant::fromValue(this->ang1Absoluto + signo*avance));
        this->animaciones.front()->setDuration(1000*avance/velocidad);

        this->paralelo.front()->addAnimation(this->animaciones.front());


        this->secuencia->addAnimation(this->paralelo.front());

        this->ang1Absoluto += signo*avance;

        //        this->rotationAxis = QVector3D(40*cos(this->ang1Absoluto*3.1416/180), 0, 40*sin(this->ang1Absoluto*3.1416/180));

        //        this->BRobot->articulacion2->setRotationAxis(this->rotationAxis);


        break;

    case 12:


        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->articulacion2->getTransform()));
        this->paralelo.push_front(new QParallelAnimationGroup());

        this->animaciones.front()->setTargetObject(this->BRobot->articulacion2->controlpieza);

        this->animaciones.front()->setPropertyName("angle2");
        this->animaciones.front()->setStartValue(QVariant::fromValue(this->ang2Absoluto));
        this->animaciones.front()->setEndValue(QVariant::fromValue(this->ang2Absoluto + signo*avance));
        this->animaciones.front()->setDuration(1000*avance/velocidad);

        this->paralelo.front()->addAnimation(this->animaciones.front());

        this->secuencia->addAnimation(this->paralelo.front());

        this->ang2Absoluto += signo*avance;

        //        this->BRobot->articulacion2->controlpieza->setArtic2Angle(ang2Absoluto);


        break;


    }
}


void Controlador::startAnimacion(){
    this->secuencia->start();
}

void Controlador::borrarSecuencia(){

    this->secuencia->clear();

    this->paralelo.clear();

}

bool Controlador::getEstadoBR(){
    return this->BRobot->getEstado();
}
void Controlador::setEstadoBR(bool estado){
    this->BRobot->setEstado(estado);
}


int Controlador::getSequenceDuration(){
    return this->secuencia->duration();
}

Controlador::~Controlador(){

    int n = this->animaciones.size();
    for (int i = 0; i<n; i++){
        delete this->animaciones.front();
    }

    n = this->paralelo.size();
    for (int i = 0; i < n; i++){
        delete this->paralelo.front();
    }

    delete this->secuencia;
    delete this->BRobot;

}

