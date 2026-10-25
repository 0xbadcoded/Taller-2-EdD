#include <iostream>
#include "Servicio.h"
#pragma once
using namespace std;

class NodoDecision {
    private:
        string pregunta;
        Servicio* servicio;
        NodoDecision* si;
        NodoDecision* no;

    public:
        NodoDecision(string pregunta) {
            this->pregunta = pregunta;
            servicio = nullptr;
            si = nullptr;
            no = nullptr;
        }

        NodoDecision(Servicio* servicio) {
            pregunta = "";
            this->servicio = servicio;
            si = nullptr;
            no = nullptr;
        }

        bool esHoja() {return servicio != nullptr;}

        void setRamas(NodoDecision* si, NodoDecision* no) {
            this->si = si;
            this->no = no;
        }

        NodoDecision* getSi() {return si;}
        NodoDecision* getNo() {return no;}
        string getPregunta() {return pregunta;}
        Servicio* getServicio() {return servicio;}
};