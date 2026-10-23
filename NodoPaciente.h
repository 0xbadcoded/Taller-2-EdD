#include <iostream>
#include "Paciente.h"
using namespace std;
#pragma once

class NodoPaciente {
    private:
        Paciente* paciente;
        NodoPaciente* siguiente;

    public:
        NodoPaciente(Paciente* paciente) {
            this->paciente = paciente;
            this->siguiente = nullptr;
        }
        ~NodoPaciente();
        Paciente* getPaciente() {return paciente;}
        NodoPaciente* getSiguiente() {return siguiente;}
        void setSiguiente(NodoPaciente* nuevo) {this->siguiente = nuevo;}
};