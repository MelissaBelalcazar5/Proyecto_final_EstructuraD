#ifndef MAPA_H
#define MAPA_H
#include "Nodo.h"
#include <cstdlib>
#include <ctime>

class Mapa {
public:
    Nodo* origen;

    Mapa();
    ~Mapa();
    void imprimir();
    Nodo* nodoAleatorio();

private:
    void construir();
    void colocarCallejones();
    void colocarPistas();
    void colocarTestigos();
};
#endif