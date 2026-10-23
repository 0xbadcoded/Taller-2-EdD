#include <iostream>
#include "NodoPaciente.h"
using namespace std;
#pragma once

class ListaPacientes {
    private:
        NodoPaciente* primero;

    public: 
        ListaPacientes() {
            this->primero = nullptr;
        }

        NodoPaciente* getPrimero() {return primero;}
        void setPrimero(NodoPaciente* nuevo) {this->primero = nuevo;}
        
        int size() {
            if(primero == nullptr) {return 0;}

            NodoPaciente* actual = primero;
            int contador = 0;

            while(actual != nullptr) {
                contador++;
                actual = actual->getSiguiente();
            }
            
            return contador;
        }
};
