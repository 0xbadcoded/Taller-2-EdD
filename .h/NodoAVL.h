#pragma once
#include "Paciente.h"

class NodoAVL {
    private:
        Paciente* paciente;
        NodoAVL* izquierda;
        NodoAVL* derecha;
        int altura;

    public:
        NodoAVL(Paciente* paciente) {
            this->paciente = paciente;
            izquierda = nullptr;
            derecha = nullptr;
            altura = 1;
        }

        Paciente* getPaciente() {return paciente;}
        string getId() {return paciente->getId();}
        NodoAVL* getDerecha() {return derecha;}
        NodoAVL* getIzquierda() {return izquierda;}
        int getAltura() {return altura;}
        void setDerecha(NodoAVL* derecha) {this->derecha = derecha;}
        void setIzquierda(NodoAVL* izquierda) {this->izquierda = izquierda;}
        void setAltura(int altura) {this->altura = altura;}
};