#include "abbPuntaje.h"
#include <iostream>

NodoABB::NodoABB(const std::string& n, int p)
    : nombre(n), mejorPuntaje(p),
      izquierdo(nullptr), derecho(nullptr) {}

// Métodos privados
NodoABB* ABBPuntajes::insertarRec(NodoABB* nodo, const std::string& nombre, int puntaje) {
    if (nodo == nullptr) return new NodoABB(nombre, puntaje);

    // Si el detective ya existe, conservar el menor puntaje
    if (nodo->nombre == nombre) {
        if (puntaje < nodo->mejorPuntaje)
            nodo->mejorPuntaje = puntaje;
        return nodo;
    }

    // Se organizan segun puntaje
    if (puntaje < nodo->mejorPuntaje)
        nodo->izquierdo = insertarRec(nodo->izquierdo, nombre, puntaje);
    else
        nodo->derecho = insertarRec(nodo->derecho, nombre, puntaje);
    return nodo;
}

NodoABB* ABBPuntajes::buscarPorNombreRec(NodoABB* nodo, const std::string& nombre) const {
    if (nodo == nullptr) return nullptr;
    if (nodo->nombre == nombre) return nodo;

    NodoABB* izq = buscarPorNombreRec(nodo->izquierdo, nombre);
    if (izq != nullptr) return izq;
    return buscarPorNombreRec(nodo->derecho, nombre);
}

void ABBPuntajes::inordenRec(NodoABB* nodo) const {
    if (nodo == nullptr) return;
    inordenRec(nodo->izquierdo);
    std::cout << "  " << nodo->nombre
              << " | Puntaje: " << nodo->mejorPuntaje << "\n";
    inordenRec(nodo->derecho);
}

void ABBPuntajes::destruirRec(NodoABB* nodo) {
    if (nodo == nullptr) return;
    destruirRec(nodo->izquierdo);
    destruirRec(nodo->derecho);
    delete nodo;
}

//  Métodos públicos
ABBPuntajes::ABBPuntajes() : raiz(nullptr) {}

ABBPuntajes::~ABBPuntajes() {
    destruirRec(raiz);
}

void ABBPuntajes::guardar(const std::string& nombre, int puntaje) {
    raiz = insertarRec(raiz, nombre, puntaje);
}

bool ABBPuntajes::buscar(const std::string& nombre, int& puntajeOut) const {
    NodoABB* nodo = buscarPorNombreRec(raiz, nombre);
    if (nodo == nullptr) return false;
    puntajeOut = nodo->mejorPuntaje;
    return true;
}

void ABBPuntajes::mostrarRanking() const {
    std::cout << "\n=== Ranking de detectives ===\n";
    if (raiz == nullptr) {
        std::cout << "  (Sin registros aun)\n\n";
        return;
    }
    inordenRec(raiz);
    std::cout << "\n";
}