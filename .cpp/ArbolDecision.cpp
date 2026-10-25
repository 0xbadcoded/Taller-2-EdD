#include "ArbolDecision.h"

ArbolDecision::ArbolDecision(Hospital* hospital) {
    Servicio* urgencias = hospital->getFront();
    Servicio* medicinaGeneral = urgencias->getSiguiente();
    Servicio* cardiologia = medicinaGeneral->getSiguiente();
    Servicio* neurologia = cardiologia->getSiguiente();
    Servicio* traumatologia = neurologia->getSiguiente();
    Servicio* cirugia = traumatologia->getSiguiente();
    Servicio* pediatria = cirugia->getSiguiente();
    Servicio* hospitalizacion = pediatria->getSiguiente();

    NodoDecision* hojaUrgencias = new NodoDecision(urgencias);
    NodoDecision* hojaMedicinaGeneral = new NodoDecision(medicinaGeneral);
    NodoDecision* hojaCardiologia = new NodoDecision(cardiologia);
    NodoDecision* hojaNeurologia = new NodoDecision(neurologia);
    NodoDecision* hojaTraumatologia = new NodoDecision(traumatologia);
    NodoDecision* hojaCirugia = new NodoDecision(cirugia);
    NodoDecision* hojaPediatria = new NodoDecision(pediatria);
    NodoDecision* hojaHospitalizacion = new NodoDecision(hospitalizacion);

    NodoDecision* preguntaDias = new NodoDecision("diasHospitalizacion >= 2");
    preguntaDias->setRamas(hojaHospitalizacion, hojaMedicinaGeneral);

    NodoDecision* preguntaDolorPecho = new NodoDecision("tipoDolor == pecho");
    preguntaDolorPecho->setRamas(hojaCardiologia, preguntaDias);

    NodoDecision* preguntaNeurologia = new NodoDecision("sintomasNeurologicos == 1");
    preguntaNeurologia->setRamas(hojaNeurologia, preguntaDolorPecho);

    NodoDecision* preguntaCirugia = new NodoDecision("requiereCirugia == 1");
    preguntaCirugia->setRamas(hojaCirugia, hojaTraumatologia);

    NodoDecision* preguntaTraumaOCirugia = new NodoDecision("Trauma == 1 || requiereCirugia == 1");
    preguntaTraumaOCirugia->setRamas(preguntaCirugia, preguntaNeurologia);

    NodoDecision* preguntaEdad = new NodoDecision("Edad >= 18");
    preguntaEdad->setRamas(preguntaTraumaOCirugia, hojaPediatria);

    NodoDecision* preguntaUrgencias = new NodoDecision("Dolor >= 8 || Temperatura >= 38.5");
    preguntaUrgencias->setRamas(hojaUrgencias, preguntaEdad);

    raiz = preguntaUrgencias;
}

Servicio* ArbolDecision::clasificar(Paciente* paciente, string& ruta) {
    if(raiz == nullptr || paciente == nullptr) {return nullptr;}

    ruta = "";
    NodoDecision* actual = raiz;

    while (!actual->esHoja()) {
        string pregunta = actual->getPregunta();
        bool respuesta;

        if (pregunta == "Dolor >= 8 || Temperatura >= 38.5") {
            respuesta = paciente->getDolor() >= 8 || paciente->getTemperatura() >= 38.5;
        }

        else if(pregunta == "Edad >= 18") {
            respuesta = paciente->getEdad() >= 18;
        }

        else if(pregunta == "Trauma == 1 || requiereCirugia == 1") {
            respuesta = paciente->getTrauma() || paciente->getRequiereCirugia();
        }

        else if(pregunta == "requiereCirugia == 1") {
            respuesta = paciente->getRequiereCirugia();
        }

        else if(pregunta == "sintomasNeurologicos == 1") {
            respuesta = paciente->getSintomasNeurologicos();
        }

        else if(pregunta == "tipoDolor == pecho") {
            respuesta = paciente->getTipoDolor() == "pecho";
        }

        else if(pregunta == "diasHospitalizacion >= 2") {
            respuesta = paciente->getDiasHospitalizado() >= 2;
        }

        else {
            return nullptr;
        }
        
        if (ruta != "") {
            ruta += "\n -> ";
        }

        ruta += "¿" + pregunta + "? = ";

        if (respuesta) {
            ruta += "Si";
            actual = actual->getSi();
        } else {
            ruta += "No";
            actual = actual->getNo();
        }

        if (actual == nullptr) {
            return nullptr;
        }
    }

    return actual->getServicio();
}