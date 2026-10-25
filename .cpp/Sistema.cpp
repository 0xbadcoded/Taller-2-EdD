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

    
    if(hospital->getFront() == nullptr) {
        texto += "No hay servicios.";
        return texto;
    }
    
    int contador = 1;
    
    Servicio* actual = hospital->getFront();

    while(actual != nullptr) {
        texto += to_string(contador) + ". " + actual->getNombre() + "\n";
        contador++;
        actual = actual->getSiguiente();
    }

    return texto;
}

void Sistema::mostrarServicios(int posicion) {
    if(hospital->getFront() == nullptr) {return;}
    
    Servicio* actual = hospital->getFront();
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

void Sistema::atenderPaciente() {
    if(lista->isEmpty()) {cout << "No hay pacientes en espera" << endl; return;}

    Paciente* paciente = lista->getFront()->getPaciente();
    string ruta;
    Servicio* servicio = arbolDecision->clasificar(paciente, ruta);

    if (servicio == nullptr) {cout << "No se pudo clasificar al paciente." << endl; return;}

    lista->pop();
    servicio->getListaPacientes().push(new NodoPaciente(paciente));
    
    cout << paciente->toString() << endl;
    cout << "Ruta: " << ruta << endl;
    cout << endl;
    cout << "Servicio asignado: " << servicio->getNombre() << endl;
    cout << endl;
}
