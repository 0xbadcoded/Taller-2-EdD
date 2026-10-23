#include <iostream>
#include <string>
#include "Sistema.h"
#include "Hospital.h"
#include "ListaPacientes.h"
#include "NodoPaciente.h"
using namespace std;

void Sistema::crearPaciente(string id, string nombre, int edad, string servicio) {
    Paciente* paciente = new Paciente(id, nombre, edad, servicio);
    NodoPaciente* nodoPaciente = new NodoPaciente(paciente);


    if(lista->getPrimero() == nullptr) {
        lista->setPrimero(nodoPaciente);
        return;
    }

    NodoPaciente* actual = lista->getPrimero();

    while(actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }

    actual->setSiguiente(nodoPaciente);

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
    
    if (lista->getPrimero() == nullptr) {
        texto += "La lista está vacía.";
        return texto;
    }

    NodoPaciente* actual = lista->getPrimero();

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

bool Sistema::verificarSiExisteServicio(string nombre) {
    if(hospital->getPrimero() == nullptr) {return false;}

    Servicio* actual = hospital->getPrimero();

    while(actual != nullptr) {
        if(actual->getNombre() == nombre) {return true;}

    actual = actual->getSiguiente();
    }

    return false;
}  

void Sistema::repletarServicios(int cantidad) {
    if(lista->getPrimero() == nullptr || hospital->getPrimero() == nullptr) {return;}

    for(int i = 0; i < cantidad; i++) {
        if(lista->getPrimero() == nullptr) {break;}
        
        NodoPaciente* nodoActual = lista->getPrimero();
        Servicio* servicioActual = hospital->getPrimero();
        Paciente* pacienteActual = nodoActual->getPaciente();

        while(servicioActual != nullptr) {
            if (pacienteActual->getServicio() == servicioActual->getNombre()) {
                ListaPacientes& listaPacientes = servicioActual->getListaPacientes();
                NodoPaciente* siguiente = nodoActual->getSiguiente();
                nodoActual->setSiguiente(nullptr);

                if(listaPacientes.getPrimero() == nullptr) {
                    listaPacientes.setPrimero(nodoActual); 

                } else {
                    NodoPaciente* actual = listaPacientes.getPrimero();

                    while(actual->getSiguiente() != nullptr) {
                        actual = actual->getSiguiente();
                    }

                    actual->setSiguiente(nodoActual);
                }

                lista->setPrimero(siguiente);
                break;
            }
            servicioActual = servicioActual->getSiguiente();
        }
        ultimoAtendido = pacienteActual;
    }
}

void Sistema::mostrarServicios(int posicion) {
    if(hospital->getPrimero() == nullptr) {return;}
    
    Servicio* actual = hospital->getPrimero();
    for(int i = 1; i < posicion; i++) {
        actual = actual->getSiguiente();
    }

    ListaPacientes& listaP = actual->getListaPacientes();

    cout << "=== ESTADO " << actual->getNombre() + " ===" << endl;
    cout << "Pacientes en el departamento de " << actual->getNombre() + ":" << listaP.size() << endl;

    NodoPaciente* nodoActual = listaP.getPrimero();

    while(nodoActual != nullptr) {
        Paciente* pacienteActual = nodoActual->getPaciente();

        cout << pacienteActual->getNombre() + "(" << pacienteActual->getEdad() << ")" << endl;
        nodoActual = nodoActual->getSiguiente();
    }
}
