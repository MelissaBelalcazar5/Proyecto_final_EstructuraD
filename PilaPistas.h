#ifndef PILAPISTAS_H
#define PILAPISTAS_H

#include "Pista.h"
#include <string>

// Nodo de la Pila
struct NodoPila {
    Pista*    pista;
    NodoPila* siguiente;
    NodoPila(Pista* p);
};

// Clase PilaPistas, maneja las pistas recogidas por el detective
class PilaPistas {
private:
    NodoPila* tope;
    int       tam;
    void imprimirOrdenado() const;

public:
    PilaPistas();
    ~PilaPistas();

    PilaPistas(const PilaPistas&)            = delete;
    PilaPistas& operator=(const PilaPistas&) = delete;

    bool estaVacia()  const; // consulta pila vacía
    int getTam() const; // consulta tamaño pila
    Pista* peek() const; // ver tope sin quitarlo

    void push(Pista* p); // apilar pista recogida
    Pista* pop(); // sacar tope al presionar X
    void mostrarVisual(const std::string& nombreDetective) const; // tecla T
};

#endif // PROYECTO_FINAL_ESTRUCTURAD_PILAPISTAS_H