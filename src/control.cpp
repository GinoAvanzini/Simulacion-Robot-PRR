#include "control.h"

#include <QTransform>



#include <iostream>



QT_BEGIN_NAMESPACE

    /*
     * Problema con vtable...
     * Por alguna razón si implemento el constructor acá me lanza ese error.
     * Si declaro e implemento el constructor en el .h anda todo.
     * Buscar solucion
     */

//Control::Control(QObject * parent)
//    : QObject (parent){}
//    , m_target(nullptr)
//    , m_matrix()
//    , m_altura(40.0f)
//    , m_angle(0.0f)
//{

//}
//Control::Control(QObject * parent) : QObject(parent)
//  , m_target(nullptr)
//  , m_matrix()
//  , m_altura(40.0f)
//  , m_angle(0.0f) {

//}



void Control::setTarget(Qt3DCore::QTransform * target){
    if (m_target != target){
        m_target = target;
        emit targetChanged();
    }
}
Qt3DCore::QTransform * Control::getTarget() const {
    return this->m_target;
}



float Control::getAltura() const {
    return this->m_altura;
}
void Control::setAltura(float altura){
    if (!qFuzzyCompare(altura, m_altura)){
        this->m_altura = altura;
        this->updateAltura();
        emit alturaChanged();
    }
    this->previous_altura = m_altura;
    this->m_altura = altura;
    this->updateAltura();
}


float Control::getAngle() const {
    return this->m_angle;
}
void Control::setAngle(float angle){
    if (!qFuzzyCompare(angle, m_angle)){
        this->m_angle = angle;
        this->updateAngle();
        emit angleChanged();
    }

    this->previous_angle = m_angle;
    this->m_angle = angle;
    this->updateAngle();

}

float Control::getAngle2() const{
    return this->m_angle2;
}
void Control::setAngle2(float angle2){
    if (!qFuzzyCompare(angle2, m_angle2)){
        this->m_angle2 = angle2;
        this->updateAngle2();
        emit angle2Changed();
    }

    this->previous_angle2 = m_angle2;
    this->m_angle2 = angle2;
    this->updateAngle2();
}

float Control::getAngle3() const{
    return this->m_angle3;
}
void Control::setAngle3(float angle3){
    if (!qFuzzyCompare(angle3, this->m_angle3)){
        this->m_angle3 = angle3;
        this->updateAngle3();
        emit angle3Changed();
    }
    this->previous_angle3 = m_angle3;
    this->m_angle3 = angle3;
    this->updateAngle3();
}


void Control::updateAngle(){

    this->m_matrix.rotate(this->m_angle - this->previous_angle, QVector3D(0.0f, 1.0f, 0.0f));
    this->m_target->setMatrix(this->m_matrix);

}

void Control::updateAngle2(){

    this->m_matrix.translate(this->rotationAxis);
    this->m_matrix.rotate(this->m_angle2 - this->previous_angle2, QVector3D(0.0f, 1.0f, 0.0f));
    this->m_matrix.translate((-1)*this->rotationAxis);

    this->m_target->setMatrix(this->m_matrix);


    //Angulo absoluto. Se usa en updateAngle3
    this->artic2Angle += (this->m_angle2 - this->previous_angle2);

}

void Control::updateAngle3(){

    this->m_matrix.translate(this->rotationAxis);
    this->m_matrix.rotate(-this->artic2Angle, QVector3D(0, 1, 0));
    this->m_matrix.translate((-1)*this->rotationAxis);

    this->m_matrix.rotate(this->m_angle3 - this->previous_angle3, QVector3D(0, 1, 0));

    this->m_matrix.translate(this->rotationAxis);
    this->m_matrix.rotate(this->artic2Angle, QVector3D(0, 1, 0));
    this->m_matrix.translate((-1)*this->rotationAxis);


    this->m_target->setMatrix(this->m_matrix);

}


void Control::updateAltura(){

    this->m_matrix.translate(QVector3D(0, this->m_altura - this->previous_altura, 0));
    this->m_target->setMatrix(this->m_matrix);

}


void Control::setRotationAxis(QVector3D eje){
    this->rotationAxis = eje;
}

void Control::setArtic2Angle(float angle){
    this->artic2Angle = angle;
}

Control::~Control(){

}


QT_END_NAMESPACE
