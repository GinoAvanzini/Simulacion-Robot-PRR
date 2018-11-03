/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BaseRobot.h
 * Author: emiliano
 *
 * Created on 3 de noviembre de 2018, 16:21
 */

#ifndef BASEROBOT_H
#define BASEROBOT_H

#include "Conjunto.h"
#include <string>
using std::string;

class BaseRobot : public Conjunto{
public:
    BaseRobot(int ID);
    BaseRobot(const BaseRobot& orig);
    virtual ~BaseRobot();
private:
    bool estado;
    string ip_data;

};

#endif /* BASEROBOT_H */
