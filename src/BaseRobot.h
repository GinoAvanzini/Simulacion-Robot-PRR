
#ifndef BASEROBOT_H
#define BASEROBOT_H

#include "Conjunto.h"
#include <string>

using std::string;

class BaseRobot : public Conjunto{
public:
    BaseRobot(int ID, bool t, string ip);
    BaseRobot(const BaseRobot& orig);
    virtual ~BaseRobot();
    void inicio();
    bool isEstado() const;
    void setEstado(bool estado);
    string getIp_data() const;
    void setIp_data(string ip_data);


private:
    bool estado;
    string ip_data;
};

#endif /* BASEROBOT_H */
