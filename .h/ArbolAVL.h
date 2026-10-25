#pragma once
#include <iostream>
#include "NodoAVL.h"

class ArbolAVL {
    private:
        NodoAVL* raiz;

    public:
        ArbolAVL() {raiz = nullptr;}
        
        void insertar(Paciente* paciente);
        NodoAVL* insertar(NodoAVL* actual, Paciente* paciente);
        NodoAVL* rotarIzquierda(NodoAVL* nodo);
        NodoAVL* rotarDerecha(NodoAVL* nodo);
        int obtenerAltura(NodoAVL* nodo);
        int obtenerBalance(NodoAVL* nodo);
        int mayor(int a, int b);
        bool isEmpty() {return raiz == nullptr;}
        void imprimirEnOrden() {imprimirEnOrden(raiz);}
        void imprimirEnOrden(NodoAVL* actual) {
            if (actual == nullptr) {return;}
            
            imprimirEnOrden(actual->getIzquierda());
            cout << actual->getPaciente()->toString() << endl;
            imprimirEnOrden(actual->getDerecha());
        }
};