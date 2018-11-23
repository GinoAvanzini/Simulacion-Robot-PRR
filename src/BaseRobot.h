
#ifndef BASEROBOT_H
#define BASEROBOT_H

#include "Conjunto.h"
#include "Articulacion.h"
#include "ActuadorLineal.h"

#include <vector>
#include <string>

using std::string;

class BaseRobot : public Conjunto{
public:
    BaseRobot(int ID, bool t, string ip);
    BaseRobot(int ID, bool t, string ip, Qt3DCore::QEntity * rootEntity, QUrl url);
    virtual ~BaseRobot();
    void inicio(Qt3DCore::QEntity * rootEntity);
    bool isEstado() const;
    void setEstado(bool estado);
    string getIp_data() const;
    void setIp_data(string ip_data);


private:
    bool estado;
    string ip_data;

    Articulacion * articulacion1;
    Articulacion * articulacion2;

    ActuadorLineal * ActLineal;





};

#endif /* BASEROBOT_H */
