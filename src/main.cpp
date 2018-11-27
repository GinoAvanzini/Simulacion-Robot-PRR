
#include "BaseRobot.h"

#include <QApplication>

#include <Qt3DCore/QEntity>

#include <src/interfaz.h>


int main(int argc, char** argv) {

    QApplication app(argc, argv);
    interfaz * window = new interfaz();

    window->setWindowTitle("Integrador POO");
    window->show();


    app.exec();

    delete window;

    return 0;

}
