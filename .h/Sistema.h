#include <iostream>
#include "Hospital.h"
#include "ListaPacientes.h"
#include "NodoPaciente.h"
#include "ArbolDecision.h"

using namespace std;

class Sistema {
    private:
        ListaPacientes* lista = new ListaPacientes();
        Hospital* hospital = new Hospital();
        ArbolDecision* arbolDecision = new ArbolDecision(hospital);

    public:
        void crearPaciente(string id, string nombre, int edad, double temperatura,
        int presionArterial, int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos,
        bool requiereCirugia, int diasHospitalizacion);
        string recorrerListaPacientes();
        string recorrerHospital();
        void atenderPaciente();
        void mostrarServicios(int posicion);

};
