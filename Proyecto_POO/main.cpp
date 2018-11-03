/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: emiliano
 *
 * Created on 30 de septiembre de 2018, 16:59
1
 *  */



#include "BaseRobot.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    int i;
    cout << "Ingrese 1 para encender el robot:"<<endl;
    cin >> i;
    if (i == 1){
        BaseRobot *robot1;
        robot1= new BaseRobot(0);    }
    else {
        return 0;
    }
}
