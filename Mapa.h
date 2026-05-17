#pragma once

#include "Nodo.h"

class Mapa {
public:
    Nodo* origen; 

    Mapa();
    ~Mapa();
    void imprimir();

private:
    void construir();
    void conectar(Nodo* a, Nodo* b, char direccion);
};