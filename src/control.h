#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

#include <Qt3DCore/QTransform>

class Control : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Qt3DCore::QTransform * target READ getTarget WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(float angle READ getAngle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(float altura READ getAltura WRITE setAltura NOTIFY alturaChanged)


public:
//    Control(QObject *parent = 0);
    Control(QObject * parent) : QObject(parent)
      , m_target(nullptr)
      , m_matrix()
//      , m_altura(400.0f)
//      , m_angle(0.0f)
    {
        this->m_matrix.setToIdentity();
    }

//    virtual ~Control();

    void setTarget(Qt3DCore::QTransform *target);
    Qt3DCore::QTransform * getTarget() const;

    void setAltura(float altura);
    float getAltura() const;

    void setAngle(float angle);
    float getAngle() const;

    void updateAngle(QVector3D point, float angle);
    void updateAltura(float altura);

signals:
    void targetChanged();
    void alturaChanged();
    void angleChanged();

protected:
    void updateMatrix();

private:
    Qt3DCore::QTransform * m_target;
    QMatrix4x4 m_matrix;
    float m_altura;
    float m_angle;


};

#endif // CONTROL_H
