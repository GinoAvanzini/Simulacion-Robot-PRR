#include "controlador.h"

Controlador::Controlador(Qt3DCore::QEntity * rootEntity)
{


    //Render de Base Robot y las articulaciones
    {
        QUrl path = QStringLiteral("qrc:/res/base_robot.obj");
        this->BRobot = new BaseRobot(0, true, "192.168.1.10", rootEntity, path);
    }
    this->BRobot->inicio(rootEntity);

}

void Controlador::agregarInstruccion(std::string instruc){
    this->instrucciones.push(instruc);
    if (instruc == "C00"){
        this->interprete();
    }
}

void Controlador::interprete(){

    int ID;
    bool sentido = true;
    int velocidad;
    int avance;

    std::string aux;
    while(!this->instrucciones.empty()){
        aux = this->instrucciones.front();
        this->instrucciones.pop();
        if(aux.front() == 'G'){
            aux.erase(0, 1);
            if (aux.front() == '1'){ //actuador lineal
                aux.erase(0, 1);
                ID = 10;
            } else if (aux.front() == '2'){ //Primera articulacion
                aux.erase(0, 1);
                ID = 11;
            } else {  // Segunda articulacion
                aux.erase(0, 1);
                ID = 12;
            }

            if (aux.front() == '1'){
                sentido = true;
            } else if (aux.front() == '2') {
                sentido = false;
            }

            aux = this->instrucciones.front();
            this->instrucciones.pop();
            velocidad = std::stoi(aux, nullptr, 10);

            aux = this->instrucciones.front();
            this->instrucciones.pop();
            avance = std::stoi(aux, nullptr, 10);

            //REALIZAR ANIMACION

            this->agregarAnimacion(ID, sentido, velocidad, avance);
            // THIS.ANIMACION(ID, SENTIDO, VELOCIDAD, AVANCE)

        } else if (aux.front() == 'C'){
//            std::cout << this->instrucciones.size() << std::endl;
//            this->startAnimacion();
        }
    }

    std::cout << "up to here" << std::endl;


}

void Controlador::agregarAnimacion(int ID, bool sentido, int velocidad, int avance){

//    switch(ID){
//    case 10:  //Actuador Lineal


//        std::list <QPropertyAnimation> animaciones;
//        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->ActLineal->getTransform()));
//        animaciones.front()->setTargetObject(this->BRobot->ActLineal->controlpieza);
//        animaciones.front()->setPropertyName("altura");
//        animaciones.front()->setStartValue(QVariant::fromValue(0));
//        animaciones.front()->setEndValue(QVariant::fromValue(avance));




        this->animacionprueba = new QPropertyAnimation(this->BRobot->ActLineal->getTransform());

        this->animacionprueba->setTargetObject(this->BRobot->ActLineal->controlpieza);
        this->animacionprueba->setPropertyName("altura");
        this->animacionprueba->setStartValue(QVariant::fromValue(0));
        this->animacionprueba->setEndValue(QVariant::fromValue(-avance));

        this->animacionprueba->setDuration(5000);
        this->animacionprueba->setLoopCount(1);

        //duration en ms. Avance y vel en mm y mm/s respectivamente
//        animaciones.front()->setDuration(avance/(velocidad*1000));
//        animaciones.front()->setLoopCount(1);

//        this->animacionprueba->start();

        this->secuencia = new QSequentialAnimationGroup();
        this->secuencia->addAnimation(this->animacionprueba);

        QPropertyAnimation * test = new QPropertyAnimation(this->BRobot->ActLineal->getTransform());
        test->setTargetObject(this->BRobot->ActLineal->controlpieza);

        test->setPropertyName("altura");
        test->setStartValue(QVariant::fromValue(0));
        test->setEndValue(QVariant::fromValue(-avance));

        test->setDuration(5000);
        test->setLoopCount(1);

        this->secuencia->addAnimation(test);

        this->secuencia->start();


//        this->paralelo.push_front(new QParallelAnimationGroup());
//        paralelo.front()->addAnimation(animaciones.front());

//        secuencia->addAnimation(animaciones.front());
//        this->startAnimacion();


//        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->articulacion1->getTransform()));
//        animaciones.front()->setPropertyName("altura");
//        animaciones.front()->setPropertyName("altura");
//        animaciones.front()->setStartValue(QVariant::fromValue(0));
//        animaciones.front()->setEndValue(QVariant::fromValue(avance));
//        animaciones.front()->setDuration(avance/(velocidad*1000));
//        animaciones.front()->setLoopCount(1);

//        paralelo.front()->addAnimation(animaciones.front());


//        this->animaciones.push_front(new QPropertyAnimation(this->BRobot->articulacion2->getTransform()));
//        animaciones.front()->setPropertyName("altura");
//        animaciones.front()->setPropertyName("altura");
//        animaciones.front()->setStartValue(QVariant::fromValue(0));
//        animaciones.front()->setEndValue(QVariant::fromValue(avance));
//        animaciones.front()->setDuration(avance/(velocidad*1000));
//        animaciones.front()->setLoopCount(1);

//        paralelo.front()->addAnimation(animaciones.front());


//        this->secuencia->addAnimation(this->paralelo.front());
//    }

}


void Controlador::startAnimacion(){
    this->secuencia->start();
}


//void agregarAnimacion(int ID, )
