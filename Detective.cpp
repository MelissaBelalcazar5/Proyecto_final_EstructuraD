#include "Detective.h"
#include <iostream>
using namespace std;

Detective::Detective(string nom, Nodo* posInicial)
    : nombre(nom), posicionActual(posInicial) {
    posicionActual->contenido = 'I';
    posicionActual->descubierto = true;
}

bool Detective::mover(char direccion) {
    Nodo* destino = nullptr;

    if (direccion == 'W') destino = posicionActual->arriba;
    else if (direccion == 'S') destino = posicionActual->abajo;
    else if (direccion == 'A') destino = posicionActual->izquierda;
    else if (direccion == 'D') destino = posicionActual->derecha;

    if (destino == nullptr) return false;

    if (destino->contenido == '#') {
        cout << "No puedes salir de la ciudad.\n";
        return false;
    }

    if (destino->contenido == '|') {
        destino->descubierto = true;
        cout << "Hay un callejon cerrado, busca otra ruta.\n";
        return false;
    }

    // Movimiento valido
    posicionActual->contenido = ' ';
    posicionActual->descubierto = true;
    posicionActual = destino;
    return true;
}