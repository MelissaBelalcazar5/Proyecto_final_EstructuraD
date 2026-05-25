#ifndef DETECTIVE_H
#define DETECTIVE_H
#include <string>
#include "Nodo.h"
using namespace std;

class Detective {
public:
    string nombre;
    int puntaje;
    Nodo* posicionActual;

    Detective(string nombre, Nodo* posicionInicial);
    bool mover(char direccion);
};
#endif