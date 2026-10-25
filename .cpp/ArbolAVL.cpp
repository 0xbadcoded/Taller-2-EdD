#include "ArbolAVL.h"
#include <iostream>

int ArbolAVL::obtenerAltura(NodoAVL* nodo) {
    if (nodo == nullptr) {return 0;}

    return nodo->getAltura();
}

int ArbolAVL::mayor(int a, int b) {
    if (a > b) {return a;}
    return b;
}

int ArbolAVL::obtenerBalance(NodoAVL* nodo) {
    if (nodo == nullptr) {return 0;}

    return obtenerAltura(nodo->getIzquierda()) - obtenerAltura(nodo->getDerecha()); 
}

NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->getIzquierda();
    NodoAVL* ramaMovida = nuevaRaiz->getDerecha();

    nuevaRaiz->setDerecha(nodo);
    nodo->setIzquierda(ramaMovida);

    nodo->setAltura(1 + mayor(
        obtenerAltura(nodo->getIzquierda()),
        obtenerAltura(nodo->getDerecha())
    ));

    nuevaRaiz->setAltura(1 + mayor(
        obtenerAltura(nuevaRaiz->getIzquierda()),
        obtenerAltura(nuevaRaiz->getDerecha())
    ));

    return nuevaRaiz;
}

NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->getDerecha();
    NodoAVL* ramaMovida = nuevaRaiz->getIzquierda();

    nuevaRaiz->setIzquierda(nodo);
    nodo->setDerecha(ramaMovida);

    nodo->setAltura(1 + mayor(
        obtenerAltura(nodo->getIzquierda()),
        obtenerAltura(nodo->getDerecha())
    ));

    nuevaRaiz->setAltura(1 + mayor(
        obtenerAltura(nuevaRaiz->getIzquierda()),
        obtenerAltura(nuevaRaiz->getDerecha())
    ));

    return nuevaRaiz;
}

void ArbolAVL::insertar(Paciente* paciente) {
    if (paciente == nullptr) {return;}

    raiz = insertar(raiz, paciente);
}

NodoAVL* ArbolAVL::insertar(NodoAVL* actual, Paciente* paciente) {
    if (actual == nullptr) {return new NodoAVL(paciente);}

    string id = paciente->getId();

     if (id < actual->getId()) {
        actual->setIzquierda(insertar(actual->getIzquierda(), paciente));
    }
    else if (id > actual->getId()) {
        actual->setDerecha(insertar(actual->getDerecha(), paciente));
    }
    else {
        return actual;
    }

     actual->setAltura(1 + mayor(
        obtenerAltura(actual->getIzquierda()),
        obtenerAltura(actual->getDerecha())
    ));

    int balance = obtenerBalance(actual);

    if (balance > 1 && id < actual->getIzquierda()->getId()) {
        return rotarDerecha(actual);
    }

    if (balance < -1 && id > actual->getDerecha()->getId()) {
        return rotarIzquierda(actual);
    }

    if (balance > 1 && id > actual->getIzquierda()->getId()) {
        actual->setIzquierda(rotarIzquierda(actual->getIzquierda()));
        return rotarDerecha(actual);
    }

    if (balance < -1 && id < actual->getDerecha()->getId()) {
        actual->setDerecha(rotarDerecha(actual->getDerecha()));
        return rotarIzquierda(actual);
    }

    return actual;
}