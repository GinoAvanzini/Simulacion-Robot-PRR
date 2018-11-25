#include "controlador.h"

Controlador::Controlador(Qt3DCore::QEntity * rootEntity)
{
    {
        QUrl path = QStringLiteral("qrc:/res/base_robot.obj");
        this->BRobot = new BaseRobot(0, true, "192.168.1.10", rootEntity, path);
    }
    this->BRobot->inicio(rootEntity);

}

void Controlador::getInstruccion(std::string instruc){
    this->instrucciones.push(instruc);
    if (instruc == "C00"){
        this->interprete();
    }
}

void Controlador::interprete(){

    int ID;
    bool sentido;
    int velocidad;
    int avance;

    std::string aux;
    aux = this->instrucciones.front();
    instrucciones.pop();
    if(aux.front() == 'G'){
        aux.erase(aux.front());
        if (aux.front() == '1'){ //actuador lineal
            aux.erase(aux.front());
            ID = 10;
        } else if (aux.front() == '2'){ //Primera articulacion
            aux.erase(aux.front());
            ID = 11;
        } else {  // Segunda articulacion
            aux.erase(aux.front());
            ID = 12;
        }

        if (aux.front() == '1'){
            sentido = true;
        } else {
            sentido = false;
        }

        aux = this->instrucciones.front();
        this->instrucciones.pop();
        velocidad = std::stoi(aux, nullptr, 10);

        aux = this->instrucciones.front();
        this->instrucciones.pop();
        avance = std::stoi(aux, nullptr, 10);

        //REALIZAR ANIMACION
        // THIS.ANIMACION(ID, SENTIDO, VELOCIDAD, AVANCE)

    } else if (aux.front() == 'C'){
        //COMENZAR ANIMACION;
    }



////    this->paralelo.push_back();

}

void Controlador::agregarAnimacion(int ID, bool sentido, int velocidad, int avance){

    switch(ID){
    case 10:  //Actuador Lineal
        this->BRobot->
    }

}


//void agregarAnimacion(int ID, )
