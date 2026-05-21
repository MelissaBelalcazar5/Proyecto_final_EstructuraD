#ifndef PROYECTO_FINAL_ESTRUCTURAD_COLATESTIGOS_H
#define PROYECTO_FINAL_ESTRUCTURAD_COLATESTIGOS_H

#pragma once
#include "Testigo.h"
#include <iostream>
#include <string>

//  Nodo de la Cola
struct NodoCola {
    Testigo*  testigo;
    NodoCola* siguiente;
    NodoCola(Testigo* t) : testigo(t), siguiente(nullptr) {}
};


//  Clase ColaTestigos: Acumula las declaraciones de los testigos pisados

class ColaTestigos {
private:
    NodoCola* frente;
    NodoCola* fin;
    int tam;

public:
    ColaTestigos() : frente(nullptr), fin(nullptr), tam(0) {}

    ~ColaTestigos() {
        while (!estaVacia()) unqueue();
    }

    // No permitir copia accidental
    ColaTestigos(const ColaTestigos&) = delete;
    ColaTestigos& operator=(const ColaTestigos&) = delete;

    bool estaVacia() const { return frente == nullptr; } // Consulta cola vacia
    int  getTamanio()const { return tam; } // Consulta tamano cola

    // Ver el siguiente sin quitarlo
    Testigo* peek() const {
        if (estaVacia()) return nullptr;
        return frente->testigo;
    }

    // Queue: Encolar al pasar por un testigo
    // Solo encola si el testigo no ha declarado antes
    void queue(Testigo* t) {
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

    // Interrogar al siguiente testigo con I
    // Devuelve el testigo interrogado; (el llamador le pide a P3: Melissa revelar atributo)
    Testigo* unqueue() {
        if (estaVacia()) return nullptr;

        NodoCola* tmp = frente;
        Testigo*  t = tmp->testigo;
        frente = frente->siguiente;
        if (frente == nullptr) fin = nullptr;
        delete tmp;
        tam--;
        return t;
    }

    // Mostrar estado de la cola
    void mostrarEstado() const {
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
        if (estaVacia()) std::cout << "(Cola vacia)\n";
        std::cout << "\n";
    }
};

#endif //PROYECTO_FINAL_ESTRUCTURAD_COLATESTIGOS_H
