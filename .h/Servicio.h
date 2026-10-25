#pragma once
#include <iostream>
#include "ArbolAVL.h"
using namespace std;

class Servicio {
    private:
        string nombre;
        Servicio* siguiente;
        ArbolAVL arbol;

    public: 
        Servicio(string nombre) {
            this->nombre = nombre;
            this->siguiente = nullptr;
        }
        string getNombre() {return nombre;}
        Servicio* getSiguiente() {return siguiente;}
        void setSiguiente(Servicio* nuevo) {this->siguiente = nuevo;}
        ArbolAVL& getArbolAVL() {return arbol;}
};