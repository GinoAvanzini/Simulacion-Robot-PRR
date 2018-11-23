
#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
#include <string>

#include <QObject>

using std::string;


class Conjunto : QObject {
public:
    void inicio();
    Conjunto();
    Conjunto(const Conjunto& orig);
    virtual ~Conjunto();

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

};

#endif /* CONJUNTO_H */
