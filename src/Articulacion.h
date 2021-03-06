
#ifndef ARTICULACION_H
#define ARTICULACION_H

#include "Conjunto.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Articulacion : public Conjunto{
public:
    Articulacion(int ID);
    virtual ~Articulacion();

    Articulacion(int ID, Qt3DCore::QEntity * rootEntity, QUrl url);

    void setBasicSettings(int ID);

    void setVelActual(float velocidad);
    float getVelActual() const;
    float getVelAng_max() const;
    float getVelAng_min() const;
    int getAngulo_max() const;
    void setAngulo_max(int angulo_max);
    int getAngulo_min() const;
    void setAngulo_min(int angulo_min);
    void agregarCoordfi(float _coordfi);
    float getCoordfi(int i);
    void mover(float fi);

    void setRotationAxis(QVector3D eje);


private:
    std::vector<float> coordfi;
    int angulo_max;
    int angulo_min;
    float vel_actual;
    float velang_max;
    float velang_min;

    QVector3D rotation = QVector3D(0, 0, 0);



};

#endif /* ARTICULACION_H */
