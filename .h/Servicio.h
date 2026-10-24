#include <iostream>
#include "ListaPacientes.h"
using namespace std;

class Servicio {
    private:
        string nombre;
        Servicio* siguiente;
        ListaPacientes lista;

    public: 
        Servicio(string nombre) {
            this->nombre = nombre;
            this->siguiente = nullptr;
        }
        string getNombre() {return nombre;}
        Servicio* getSiguiente() {return siguiente;}
        void setSiguiente(Servicio* nuevo) {this->siguiente = nuevo;}
        ListaPacientes& getListaPacientes() {return lista;}
};