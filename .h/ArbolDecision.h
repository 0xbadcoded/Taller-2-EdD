#pragma once

#include <iostream>
#include "NodoDecision.h"
#include "Hospital.h"
#include "Paciente.h"

/*
¿Dolor >= 8 || Temperatura >= 38.5?
|-- Si: Urgencia
|
|-- No:
    ¿Edad >= 18 años?
    |-- No: Pediatria
    |
    |-- Si:
        ¿Trauma == 1 || requiereCirugia == 1?
        |-- Si:
            ¿requiereCirugia == 1?
            |-- Si: Cirugia
            |-- No: Traumatologia
        |
        |
        |-- No:
            ¿sintomasNeurologicos == 1?
            |-- Si: Neurologia
            |
            |-- No:
                ¿tipoDolor == "pecho"?
                |-- Si: Cardiología
                |
                |-- No:
                    ¿diasHospitalizacion >= 2?
                    |-- Si: Hospitalizacion
                    |-- No: Medicina general
*/ 

class ArbolDecision {
    private:
        NodoDecision* raiz;
    
    public:
        ArbolDecision(Hospital* hospital);
        Servicio* clasificar(Paciente* paciente, string& ruta);
        ~ArbolDecision();
};