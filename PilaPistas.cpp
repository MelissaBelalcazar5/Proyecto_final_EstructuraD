#include "PilaPistas.h"
#include <iostream>


//  NodoPila
NodoPila::NodoPila(Pista* p) : pista(p), siguiente(nullptr) {}

//  Métodos privados
void PilaPistas::imprimirOrdenado() const {
    NodoPila* ptrs[tam];
    NodoPila* actual = tope;
    for (int i = tam - 1; i >= 0; i--) {
        ptrs[i] = actual;
        actual  = actual->siguiente;
    }

    // Impresión de pila
    std::cout << "  +-------+\n";  // tope
    for (int i = tam - 1; i >= 0; i--) {
        std::string tipo     = ptrs[i]->pista->getSimbolo();
        std::string etiqueta = "";
        if (i == tam - 1) etiqueta = "  <- ultima (usar con X)";
        else if (i == tam - 2) etiqueta = "  <- penultima";
        else if (i == tam - 3) etiqueta = "  <- antepenultima";
        std::cout << "  | # " << tipo << " # |" << etiqueta << "\n";
    }
    std::cout << "  +-------+\n";  // base
}


//  Métodos públicos
PilaPistas::PilaPistas() : tope(nullptr), tam(0) {}

PilaPistas::~PilaPistas() {
    while (!estaVacia()) pop();
}

bool PilaPistas::estaVacia() const { return tope == nullptr; }
int  PilaPistas::getTam() const { return tam; }

Pista* PilaPistas::peek() const {
    if (estaVacia()) return nullptr;
    return tope->pista;
}

// Push: apilar pista recogida
void PilaPistas::push(Pista* p) {
    NodoPila* nuevo = new NodoPila(p);
    nuevo->siguiente = tope;
    tope = nuevo;
    tam++;
}

// Pop: sacar pista del tope al presionar X
Pista* PilaPistas::pop() {
    if (estaVacia()) return nullptr;
    NodoPila* tmp = tope;
    Pista*    p   = tmp->pista;
    tope = tope->siguiente;
    delete tmp;
    tam--;
    return p;
}

// mostrarVisual: mostrar pila al presionar T
void PilaPistas::mostrarVisual(const std::string& nombreDetective) const {
    std::cout << "\n" << nombreDetective
              << ", mira las pistas que llevas:\n\n";
    if (estaVacia()) {
        std::cout << "  (No has recogido pistas aun)\n\n";
        return;
    }
    imprimirOrdenado();
    std::cout << "\n";
}