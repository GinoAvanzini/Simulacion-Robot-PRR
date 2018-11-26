
#include "BaseRobot.h"

#include <iostream>

#include <QApplication>

#include <Qt3DCore/QEntity>

#include <src/interfaz.h>

using std::cin;
using std::cout;
using std::endl;


int main(int argc, char** argv) {

    QApplication app(argc, argv);
    interfaz * window = new interfaz();

    window->setWindowTitle("Integrador POO");
    window->show();

    app.exec();

    delete window;




    return 0;
}
