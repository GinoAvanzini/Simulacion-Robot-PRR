
#ifndef ACTUADORLINEAL_H
#define ACTUADORLINEAL_H

#include "Conjunto.h"
#include <vector>

using std::vector;

class ActuadorLineal : public Conjunto{
public:
    ActuadorLineal(int ID);
    ActuadorLineal(int ID, Qt3DCore::QEntity * rootEntity, QUrl url);
    virtual ~ActuadorLineal();

    void setBasicSettings();

    void setVelActual(float velocidad);
    float getVelActual() const;
    float getVelLine_max() const;
    float getVelLine_min() const;
    int getDistancia_max() const;
    int getDistancia_min() const;
    void agregarCoordz(float _coordz);
    float getCoordz(int i);
    void moverl(float z);
private:

    std::vector<float> coordz;
    int distancia_max;
    int distancia_min;
    float vel_actual;
    float veline_max;
    float veline_min;

};

#endif /* ACTUADORLINEAL_H */
