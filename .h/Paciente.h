#include <iostream>
using namespace std;

class Paciente {
    private:
        string id;
        string nombre;
        int edad;
        double temperatura;
        int presionArterial;
        int dolor;
        string tipoDolor;
        bool trauma;
        bool sintomasNeurologicos;
        bool requiereCirugia;
        int diasHospitalizacion; 
        
    public:
        Paciente(string id, string nombre, int edad, double temperatura,
        int presionArterial, int dolor, string tipoDolor, bool trauma, 
        bool sintomasNeurologicos, bool requiereCirugia, int diasHospitalizacion) {
            this->id = id;
            this->nombre = nombre;
            this->edad = edad;
            this->temperatura = temperatura;
            this->presionArterial = presionArterial;
            this->dolor = dolor;
            this->tipoDolor = tipoDolor;
            this->trauma = trauma;
            this->sintomasNeurologicos = sintomasNeurologicos;
            this->requiereCirugia = requiereCirugia;
            this->diasHospitalizacion = diasHospitalizacion;
        }
        ~Paciente();
        string getId() {return id;}
        string getNombre() {return nombre;}
        int getEdad() {return edad;}
        double getTemperatura() {return temperatura;}
        int getPresionArterial() {return presionArterial;}
        int getDolor() {return dolor;}
        string getTipoDolor() {return tipoDolor;}
        bool getTrauma() {return trauma;}
        bool getSintomasNeurologicos() {return sintomasNeurologicos;}
        bool getRequiereCirugia() {return requiereCirugia;}
        int getDiasHospitalizado() {return diasHospitalizacion;}
};