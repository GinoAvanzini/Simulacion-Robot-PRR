
#-------------------------------------------------
#
# Project created by QtCreator 2018-11-10T14:53:02
#
#-------------------------------------------------

QT += core gui 3dcore 3drender 3dinput 3dlogic 3dextras 3danimation 3drender

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Integrador_POO
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        src/main.cpp \
    src/ActuadorLineal.cpp \
    src/Articulacion.cpp \
    src/BaseRobot.cpp \
    src/Conjunto.cpp \
    src/EfectorFinal.cpp \
    src/Eslabon.cpp \
    src/Programa.cpp \
    src/interfaz.cpp \
    src/control.cpp \
    src/controlador.cpp
    
HEADERS += \
    src/ActuadorLineal.h \
    src/Articulacion.h \
    src/BaseRobot.h \
    src/Conjunto.h \
    src/EfectorFinal.h \
    src/Eslabon.h \
    src/Programa.h \
    src/interfaz.h \
    src/control.h \
    src/controlador.h

FORMS += \
    src/interfaz.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    modelo.qrc
