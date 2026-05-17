#pragma once

struct Nodo {
    int fila;
    int col;
    char contenido;   
    bool descubierto;

    Nodo* arriba;
    Nodo* abajo;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int f, int c, char cont = 'o')
        : fila(f), col(c), contenido(cont), descubierto(false),
          arriba(nullptr), abajo(nullptr),
          izquierda(nullptr), derecha(nullptr) {}
};