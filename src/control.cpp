#include "control.h"

#include <QTransform>



#include <iostream>



QT_BEGIN_NAMESPACE

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
//    return 400;
}
void Control::setAltura(float altura){
    if (!qFuzzyCompare(altura, m_altura)){
        this->m_altura = altura;
        //        updateMatrix();
        this->updateAltura();
        emit alturaChanged();
    }
    this->previous_altura = m_altura;
    this->m_altura = altura;
    this->updateAltura();
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
float Control::getAngle() const {
    return this->m_angle;
}


void Control::updateAngle(){


//    QMatrix4x4 aux = new QTransform();
//    this->m_target->rotateAround();
//    this->m_matrix = QTransform

//    this->m_target->setTranslation(QVector3D(0, 40, 0));

//    this->m_target->rotateAround()

    this->m_matrix.rotate(this->m_angle - this->previous_angle, QVector3D(0.0f, 1.0f, 0.0f));


    this->m_target->setMatrix(this->m_matrix);




//    this->m_target->setTranslation(QVector3D(0, -40, 0));

//    this->m_target->rotateAround();

}


void Control::updateAltura(){

    this->m_matrix.translate(QVector3D(0, this->m_altura - this->previous_altura, 0));
    this->m_target->setMatrix(this->m_matrix);

//    this->m_target->setTranslation(QVector3D(0, altura, 0));

//    this->m_target->setMatrix(this->m_matrix.translate(QVector3D(0, altura, 0)));
}


Control::~Control(){

}


QT_END_NAMESPACE
