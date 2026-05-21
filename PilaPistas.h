#ifndef PROYECTO_FINAL_ESTRUCTURAD_PILAPISTAS_H
#define PROYECTO_FINAL_ESTRUCTURAD_PILAPISTAS_H

#pragma once
#include "Pista.h"
#include <iostream>
#include <string>

//  Nodo de la Pila
struct NodoPila {
    Pista* pista;
    NodoPila* siguiente;
    NodoPila(Pista* p) : pista(p), siguiente(nullptr) {}
};

//  Clase pistamaneja las pistas recogidas por el detective

class PilaPistas {
private:
    NodoPila* tope;
    int tam;

    // Imprime de base a tope usando un arreglo temporal de punteros
    void imprimirOrdenado() const {
        NodoPila* ptrs[tam];
        NodoPila* actual = tope;
        for (int i = tam - 1; i >= 0; i--) {
            ptrs[i] = actual;
            actual  = actual->siguiente;
        }

        std::cout << "  +-------+\n";  // tope
        for (int i = tam - 1; i >= 0; i--) {
            std::string tipo = ptrs[i]->pista->getSimbolo();
            std::string etiqueta = "";
            if (i == tam - 1) etiqueta = "  <- ultima (usar con X)";
            else if (i == tam - 2) etiqueta = "  <- penultima";
            else if (i == tam - 3) etiqueta = "  <- antepenultima";
            std::cout << "  | # " << tipo << " # |" << etiqueta << "\n";
        }
        std::cout << "  +-------+\n";  // base
    }

public:
    PilaPistas() : tope(nullptr), tam(0) {}

    ~PilaPistas() {
        while (!estaVacia()) pop();
    }

    PilaPistas(const PilaPistas&) = delete;
    PilaPistas& operator=(const PilaPistas&) = delete;

    bool estaVacia() const { return tope == nullptr; } // Consulta pila vacia
    int  getTamanio()const { return tam; } // Consulta tamano pila

    // Ver el tope sin quitarlo
    Pista* peek() const {
        if (estaVacia()) return nullptr;
        return tope->pista;
    }

    // Push, para apilar la pista recogida
    void push(Pista* p) {
        NodoPila* nuevo = new NodoPila(p);
        nuevo->siguiente = tope;
        tope = nuevo;
        tam++;
    }

    // Pop, para sacar la pista del tope para usarla presionando x
    Pista* pop() {
        if (estaVacia()) return nullptr;
        NodoPila* tmp = tope;
        Pista* p = tmp->pista;
        tope = tope->siguiente;
        delete tmp;
        tam--;
        return p;
    }

    // Mostrar visualmente al presionar t
    void mostrarVisual(const std::string& nombreDetective) const {
        std::cout << "\n" << nombreDetective
                  << ", mira las pistas que llevas:\n\n";
        if (estaVacia()) {
            std::cout << "  (No has recogido pistas aun)\n\n";
            return;
        }
        imprimirOrdenado();
        std::cout << "\n";
    }
};

#endif //PROYECTO_FINAL_ESTRUCTURAD_PILAPISTAS_H
