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


#include "EfectorFinal.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    
	int tarea=0;
	bool estado=0;
	int ciclos=0;
	bool flag=true;
        int cont=0;
        int encendido=0;
        int i=0,velocidad=0;


	cout<<"Para encender el efector presione 1:\n";
        cin>>encendido;
        if (encendido!=1){
            return 1;
        }
        else{
            EfectorFinal *efector1;
            efector1=new EfectorFinal(0);
            while(flag==true){
                cout<<"Ingrese:"<<endl
                    <<"0 para INICIAR\n"
                    <<"1 para PINTAR\n"
                    <<"2 para SOSTENER\n"
                    <<"3 para SOLTAR\n"
                    <<"4 para ROTAR\n"
                    <<"5 para CAMBIAR VELOCIDAD"<<endl;
                cin>>tarea;
            
            if(tarea!=0){
                if(tarea!=5){
                  cout<<"Indique la cantidad de ciclos que dura dicha tarea:"<<endl;
                  cin>>ciclos;
                  efector1->agregar(tarea,ciclos);
                  cont++;}
                else{
                  cout<<"Indique la cantidad de ciclos que dura dicha tarea:"<<endl;
                  cin>>ciclos;
                  cout<<endl;
                  cout<<"Indique la nueva velocidad:"<<endl;
                  efector1->agregar(tarea,ciclos);
                  cont++;   
                }    
            }
            else{
             flag=false;
            }
            
            }
            for(i=0;i<cont;i++){
              efector1->iniciar(i);
            }
        }
	return 0;
}