#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sistema.h"
using namespace std;
Sistema* sistema = new Sistema();

void leerArchivo() {
    ifstream arch("pacientes.txt");
    string linea;

    while(getline(arch, linea)){
        stringstream ss(linea);
        string id, nombre, stringEdad, stringTemperatura, stringPresionArterial, 
        stringDolor, tipoDolor, stringTrauma, stringSintomasNeurologicos, stringRequiereCirugia,
        stringDiasHospitalizacion;
        
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, stringEdad, ';');
        getline(ss, stringTemperatura, ';');
        getline(ss, stringPresionArterial, ';');
        getline(ss, stringDolor, ';');
        getline(ss, tipoDolor, ';');
        getline(ss, stringTrauma, ';');
        getline(ss, stringSintomasNeurologicos, ';');
        getline(ss, stringRequiereCirugia, ';');
        getline(ss, stringDiasHospitalizacion, ';');

        int edad = stoi(stringEdad);  
        double temperatura = stod(stringTemperatura);
        int presionArterial = stoi(stringPresionArterial);
        int dolor = stoi(stringDolor);
        bool trauma = stoi(stringTrauma) != 0;
        bool sintomasNeurologicos = stoi(stringSintomasNeurologicos) != 0;
        bool requiereCirugia = stoi(stringRequiereCirugia) != 0;
        int diasHospitalizacion = stoi(stringDiasHospitalizacion);
        
        sistema->crearPaciente(id, nombre, edad, temperatura, presionArterial,
        dolor, tipoDolor, trauma, sintomasNeurologicos, requiereCirugia, diasHospitalizacion);
    }
}

void mostrarPacientes() {
    cout << sistema->recorrerListaPacientes() << endl;
}

void mostrarServicios() {
    cout << sistema->recorrerHospital() << endl;
}

int main() {
    leerArchivo();
    

    int opcion;

    do {
        cout << "=== HOSPITAL LOS UCENINES ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Salir" << endl;
        cout << endl;
        cin>>opcion;

        switch(opcion) {
            case 1:
                cout << "=== ATENDIENDO PACIENTES ===" << endl;
                
                sistema->atenderPaciente();

                break;
            case 2:
                mostrarServicios();

                cout << "Seleccionar opción: " << endl;
                int opc;

                cin>>opc;
                sistema->mostrarServicios(opc);

                break;
            case 3:
            case 4:
                break;
        }

       

    } while(opcion != 4);
}

