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

        Paciente* pop() {
            if (isEmpty()) {return nullptr;}

            NodoPaciente* temp = primero;
            Paciente* paciente = temp->getPaciente();

            primero = primero->getSiguiente();
            temp->setSiguiente(nullptr);
            delete temp;
            
            return paciente;
        }

        NodoPaciente* front() {return primero;}
        bool isEmpty() {return primero == nullptr;}

};
