#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;

void Sistema::crearPaciente(string id, string nombre, int edad, double temperatura,
int presionArterial, int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos,
bool requiereCirugia, int diasHospitalizacion) {
    
    Paciente* paciente = new Paciente(id, nombre, edad, temperatura, presionArterial,
    dolor, tipoDolor, trauma, sintomasNeurologicos, requiereCirugia, diasHospitalizacion);
    
    NodoPaciente* nodoPaciente = new NodoPaciente(paciente);

    if(lista->isEmpty()) {
        lista->setFront(nodoPaciente);
        return;
    }

    lista->push(nodoPaciente);

    return;
}

void Sistema::crearServicio(string nombre) {
    Servicio* servicio = new Servicio(nombre);

    if(hospital->getPrimero() == nullptr) {
        hospital->setPrimero(servicio);
        return;
    }

    Servicio* actual = hospital->getPrimero();

    while(actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }

    actual->setSiguiente(servicio);

    return;
}

string Sistema::recorrerListaPacientes() {
    cout << endl;
    string texto;
    
    if (lista->isEmpty()) {
        texto += "La lista está vacía.";
        return texto;
    }

    NodoPaciente* actual = lista->getFront();

    int contador = 1;

    while(actual != nullptr) {
        Paciente* paciente = actual->getPaciente();

        texto += to_string(contador) + ". " + paciente->getId() + " - " + paciente->getNombre() + "\n";
        contador++;
        actual = actual->getSiguiente();
    }

    return texto;
    cout << endl;
}

string Sistema::recorrerHospital() {
    cout << endl;
    string texto = "";

    
    if(hospital->getPrimero() == nullptr) {
        texto += "No hay servicios.";
        return texto;
    }
    
    int contador = 1;
    
    Servicio* actual = hospital->getPrimero();

    while(actual != nullptr) {
        texto += to_string(contador) + ". " + actual->getNombre() + "\n";
        contador++;
        actual = actual->getSiguiente();
    }

    return texto;
}

void Sistema::repletarServicios(int cantidad) {}

void Sistema::mostrarServicios(int posicion) {
    if(hospital->getPrimero() == nullptr) {return;}
    
    Servicio* actual = hospital->getPrimero();
    for(int i = 1; i < posicion; i++) {
        actual = actual->getSiguiente();
    }

    ListaPacientes& listaP = actual->getListaPacientes();

    cout << "=== ESTADO " << actual->getNombre() + " ===" << endl;
    cout << "Pacientes en el departamento de " << actual->getNombre() + ":" << listaP.size() << endl;

    NodoPaciente* nodoActual = listaP.getFront();

    while(nodoActual != nullptr) {
        Paciente* pacienteActual = nodoActual->getPaciente();

        cout << pacienteActual->getNombre() + "(" << pacienteActual->getEdad() << ")" << endl;
        nodoActual = nodoActual->getSiguiente();
    }
}
