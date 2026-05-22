#include "ColaTestigos.h"
#include <iostream>

//  NodoCola
NodoCola::NodoCola(Testigo* t) : testigo(t), siguiente(nullptr) {}


//  Métodos públicos
ColaTestigos::ColaTestigos() : frente(nullptr), fin(nullptr), tam(0) {}

ColaTestigos::~ColaTestigos() {
    while (!estaVacia()) unqueue();
}

bool ColaTestigos::estaVacia() const { return frente == nullptr; } // Consulta está vacia
int  ColaTestigos::getTam() const { return tam; } // Consulta tamano

Testigo* ColaTestigos::peek() const {
    if (estaVacia()) return nullptr;
    return frente->testigo;
}

// Queue: encolar al pasar por un testigo. Solo encola si el testigo no ha declarado antes
void ColaTestigos::queue(Testigo* t) {
    if (t->isYaDeclarado()) return;

    NodoCola* nuevo = new NodoCola(t);
    if (estaVacia()) {
        frente = fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
    t->setYaDeclarado(true);
    tam++;

    std::cout << "  [Testigo] Declaracion registrada en la cola.\n";
}

// Unqueue: interrogar al siguiente testigo con tecla I. Devuelve el testigo; el llamador le pide a P3: Melissa revelar un atributo
Testigo* ColaTestigos::unqueue() {
    if (estaVacia()) return nullptr;

    NodoCola* tmp = frente;
    Testigo*  t   = tmp->testigo;
    frente = frente->siguiente;
    if (frente == nullptr) fin = nullptr;
    delete tmp;
    tam--;
    return t;
}

void ColaTestigos::mostrarEstado() const {
    std::cout << "\n=== Cola de testigos pendientes: "
              << tam << " ===\n";
    NodoCola* actual = frente;
    int i = 1;
    while (actual != nullptr) {
        std::cout << "  " << i++ << ". ";
        actual->testigo->mostrar();
        std::cout << "\n";
        actual = actual->siguiente;
    }
    if (estaVacia()) std::cout << "  (Cola vacia)\n";
    std::cout << "\n";
}