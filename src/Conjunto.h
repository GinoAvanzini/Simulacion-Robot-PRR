
#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
#include <string>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>

#include <Qt3DRender/QMesh>

#include <Qt3DExtras/QPhongMaterial>

#include <QObject>

using std::string;


class Conjunto : QObject {
public:
    void inicio();
    Conjunto(int ID);
    Conjunto(int ID, Qt3DCore::QEntity * rootEntity, QUrl url);
    Conjunto(const Conjunto& orig);
    virtual ~Conjunto();

    void setMaterial(Qt3DCore::QEntity * rootEntity);

    string getDescripcion() const;
    void setDescripcion(string descripcion);

    int getId() const;
    void setId(int id);

    int getPeso() const;
    void setPeso(int peso);

    string getTipo() const;
    void setTipo(string tipo);

private:
    int id;
    int peso;
    string descripcion;
    string tipo;

    Qt3DCore::QEntity * entity;
    Qt3DCore::QTransform * transform;
    Qt3DRender::QMesh * mesh;

    Qt3DExtras::QPhongMaterial * material;



};

#endif /* CONJUNTO_H */
