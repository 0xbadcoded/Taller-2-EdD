#include <iostream>
using namespace std;

class Paciente {
    private:
        string id;
        string nombre;
        int edad;
        string servicio;
    public:
        Paciente(string id, string nombre, int edad, string servicio) {
            this->id = id;
            this->nombre = nombre;
            this->edad = edad;
            this->servicio = servicio;
        }
        ~Paciente();
        string getId() {return id;}
        string getNombre() {return nombre;}
        int getEdad() {return edad;}
        string getServicio() {return servicio;}

};