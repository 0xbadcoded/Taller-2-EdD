#include <iostream>
#include "Servicio.h"
using namespace std;
#pragma once

class Hospital {
    private:
        string nombre;
        Servicio* front;
         
    public:
        Hospital() {
            this-> nombre = "Los Ucenines";
            this->front = nullptr;
            introducirServicios();
        }
        void introducirServicios() {
            push(new Servicio("Urgencias"));
            push(new Servicio("Medicina general"));
            push(new Servicio("Cardiologia"));
            push(new Servicio("Neurologia"));
            push(new Servicio("Traumatologia"));
            push(new Servicio("Cirugia"));
            push(new Servicio("Pediatria"));
            push(new Servicio("Hospitalizacion"));
        }

        void push(Servicio* servicio) {
            if (isEmpty()) {front = servicio; return;}

            Servicio* actual = front;

            while(actual->getSiguiente() != nullptr) {
                actual = actual->getSiguiente();
            }

            actual->setSiguiente(servicio);
            return;
        }

        Servicio* getFront() {return front;}
        bool isEmpty() {return front == nullptr;}
};