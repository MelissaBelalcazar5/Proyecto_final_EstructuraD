#ifndef COLATESTIGOS_H
#define COLATESTIGOS_H

#include "Testigo.h"
#include <string>

// Nodo de la Cola
struct NodoCola {
    Testigo*  testigo;
    NodoCola* siguiente;
    NodoCola(Testigo* t);
};

// Clase ColaTestigos — acumula las declaraciones de los testigos pisados (ítem 17)
class ColaTestigos {
private:
    NodoCola* frente;
    NodoCola* fin;
    int       tam;

public:
    ColaTestigos();
    ~ColaTestigos();

    ColaTestigos(const ColaTestigos&)            = delete;
    ColaTestigos& operator=(const ColaTestigos&) = delete;

    bool     estaVacia()  const;  // consulta cola vacía
    int      getTam() const;  // consulta tamaño cola
    Testigo* peek()       const;  // ver frente sin quitarlo

    void     queue(Testigo* t);   // encolar al pisar un testigo
    Testigo* unqueue();           // interrogar siguiente con tecla I
    void     mostrarEstado() const;
};

#endif // PROYECTO_FINAL_ESTRUCTURAD_COLATESTIGOS_H