/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.cpp
 * Author: emiliano
 * 
 * Created on 4 de noviembre de 2018, 14:16
 */

#include "Programa.h"

Programa::Programa() {
}

Programa::Programa(const Programa& orig) {
}

Programa::~Programa() {
}

void Programa::leer(){
     ifstream archivo("Datos.txt", ios::noreplace);
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
    return 0;
} 

float Programa::escribir(string i){
    
    ofstream archivo("Datos.txt", ios::trunc);
    
    archivo<<i<<endl;
}
