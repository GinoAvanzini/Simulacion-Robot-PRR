
#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <fstream>

using std::string;

class Programa {
public:
    Programa();
    Programa(const Programa& orig);
    virtual ~Programa();
    void leer();
    float escribir(string i);
private:

};

#endif /* PROGRAMA_H */

