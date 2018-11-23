
#include "Programa.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;


Programa::Programa() {
}

Programa::Programa(const Programa& orig) {
}

Programa::~Programa() {
}

void Programa::leer(){
    ifstream archivo("Datos.txt");
    //     ifstream archivo("Datos.txt", ios::noreplace);
    char linea[128];
    long contador = 0L;

    if(archivo.fail())
        cerr << "Error al abrir el archivo Datos.txt" << endl;
    else
        while(!archivo.eof())
        {
            archivo.getline(linea, sizeof(linea));

            cout << linea << endl;
        }
    archivo.close();
} 

float Programa::escribir(string i){
    
    //    ofstream archivo("Datos.txt", ios::trunc);
    ofstream archivo("Datos.txt");

    archivo << i << endl;
}
