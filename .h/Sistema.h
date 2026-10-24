#include <iostream>
#include "Hospital.h"
#include "ListaPacientes.h"
#include "NodoPaciente.h"

using namespace std;

class Sistema {
    private:
        ListaPacientes* lista = new ListaPacientes();
        Hospital* hospital = new Hospital("Hospital");
        Paciente* ultimoAtendido = nullptr;

    public:
        void crearPaciente(string id, string nombre, int edad, double temperatura,
        int presionArterial, int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos,
        bool requiereCirugia, int diasHospitalizacion);
        void crearServicio(string nombre);
        string recorrerListaPacientes();
        string recorrerHospital();
        void repletarServicios(int cantidad);
        void mostrarServicios(int posicion);

};