#include "Mapa.h"
#include <iostream>
using namespace std;

Mapa::Mapa() {
    construir();
}

void Mapa::construir() {
    
    Nodo* grilla[11][11];

    for (int f = 0; f < 11; f++) {
        for (int c = 0; c < 11; c++) {
            char cont = 'o';
            if (f == 0 || f == 10 || c == 0 || c == 10)
                cont = '#';
            grilla[f][c] = new Nodo(f, c, cont);
        }
    }

    
    for (int f = 0; f < 11; f++) {
        for (int c = 0; c < 11; c++) {
            if (f > 0)  grilla[f][c]->arriba    = grilla[f-1][c];
            if (f < 10) grilla[f][c]->abajo     = grilla[f+1][c];
            if (c > 0)  grilla[f][c]->izquierda = grilla[f][c-1];
            if (c < 10) grilla[f][c]->derecha   = grilla[f][c+1];
        }
    }

    
    origen = grilla[0][0];
}

void Mapa::imprimir() {
    Nodo* fila = origen;
    while (fila != nullptr) {
        Nodo* actual = fila;
        while (actual != nullptr) {
            cout << actual->contenido << " ";
            actual = actual->derecha;
        }
        cout << "\n";
        fila = fila->abajo;
    }
}