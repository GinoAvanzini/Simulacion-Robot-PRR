#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

#include <Qt3DCore/QTransform>

class Control : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Qt3DCore::QTransform * target READ getTarget WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(float angle READ getAngle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(float angle2 READ getAngle2 WRITE setAngle2 NOTIFY angle2Changed)

    // Esta qproperty hace lo mismo que angle solo que para la segunda articulacion
    // Para ver el uso de previous_angle ver primero la implementación de UpdateAngle
    // Para guardar el ángulo que tiene la segunda articulación respecto a la primera
    // tenemos
    Q_PROPERTY(float angle3 READ getAngle3 WRITE setAngle3 NOTIFY angle3Changed)

    Q_PROPERTY(float altura READ getAltura WRITE setAltura NOTIFY alturaChanged)

public:
//    Control(QObject *parent = 0);
    Control(QObject * parent) : QObject(parent)
      , m_target(nullptr)
      , m_matrix()
      , m_altura(40.0f)
//      , m_angle(0.0f)
    {
        this->m_matrix.setToIdentity();
        this->m_matrix2.setToIdentity();
    }

    ~Control();

    void setTarget(Qt3DCore::QTransform *target);
    Qt3DCore::QTransform * getTarget() const;

    void setAltura(float altura);
    float getAltura() const;

    void setAngle(float angle);
    void setAngle2(float angle);
    void setAngle3(float angle);

    float getAngle() const;
    float getAngle2() const;
    float getAngle3() const;

    void updateAngle();
    void updateAngle2();
    void updateAngle3();
    void updateAltura();

    void setRotationAxis(QVector3D eje);
    void setArtic2Angle(float angle);


signals:
    void targetChanged();
    void alturaChanged();
    void angleChanged();
    void angle2Changed();
    void angle3Changed();

protected:
    void updateMatrix();

private:

    Qt3DCore::QTransform * m_target;
    QMatrix4x4 m_matrix;
    QMatrix4x4 m_matrix2;
    float m_altura;
    float m_angle;
    float m_angle2;
    float m_angle3;

    QVector3D rotationAxis;

    float previous_altura = 0;

    float previous_angle = 0;
    float previous_angle2 = 0;
    float previous_angle3 = 0;

    //Ángulo de la segunda articulacion respecto a la primera
    float artic2Angle = 0;



};

#endif // CONTROL_H
