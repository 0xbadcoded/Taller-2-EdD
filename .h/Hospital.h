#include <iostream>
#include "Servicio.h"
using namespace std;
#pragma once

class Hospital {
    private:
        string nombre;
        Servicio* primero;
        
    public:
        Hospital(string nombre) {
            this->nombre = nombre; 
            this->primero = nullptr;
        }
        string getNombre() {return nombre;}
        Servicio* getPrimero() {return primero;}
        void setPrimero(Servicio* servicio) {this->primero = servicio;}
};