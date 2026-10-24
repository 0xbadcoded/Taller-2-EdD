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

        void setFront(NodoPaciente* nuevo) {this->primero = nuevo;}
        NodoPaciente* getFront() {return primero;}
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
        
        void push(NodoPaciente* paciente) {
            if (isEmpty()) {
                primero = paciente;
                return;
            }

            NodoPaciente* actual = primero;
            while(actual->getSiguiente() != nullptr) {
                actual = actual->getSiguiente();
            }

            actual->setSiguiente(paciente);
            return;
        }

        void pop() {
            if (isEmpty()) {return;}

            NodoPaciente* actual = primero->getSiguiente();
            delete primero;
            primero = actual;
            return;
        };

        NodoPaciente* front() {return primero;}
        bool isEmpty() {return primero == nullptr;}

};
