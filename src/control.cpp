#include "control.h"

#include <QTransform>

Control::Control(QObject * parent)
    : QObject (parent)
    , m_target(nullptr)
    , m_matrix()
    , m_altura(40.0f)
    , m_angle(0.0f)
{

}

void Control::setTarget(Qt3DCore::QTransform * target){
    if (m_target != target){
        m_target = target;
        emit targetChanged();
    }
}
Qt3DCore::QTransform * Control::getTarget() const {
    return this->m_target;
}


void Control::setAltura(float altura){
    if (!qFuzzyCompare(altura, m_altura)){
        this->m_altura = altura;
        updateMatrix();
        emit alturaChanged();
    }
}
float Control::getAltura() const {
    return this->m_altura;
}


void Control::setAngle(float angle){
    if (!qFuzzyCompare(angle, m_angle)){
        m_angle = angle;
        updateMatrix();
        emit angleChanged();
    }
}
float Control::getAngle() const {
    return this->m_angle;
}


void Control::updateAngle(QVector3D point, float angle){

//    QMatrix4x4 aux = new QTransform();
//    this->m_target->rotateAround();
//    this->m_matrix = QTransform

    this->m_target->rotateAround(point, angle, QVector3D(0, 0, 1));

}


void Control::updateAltura(float altura){

    this->m_target->setTranslation(QVector3D(0, 0, altura));

}
