#include "Mapa.h"
#include <iostream>
using namespace std;

Mapa::Mapa() {
    srand(time(nullptr));
    construir();
    colocarCallejones();
    colocarPistas();
    colocarTestigos();
}

Mapa::~Mapa() {
    Nodo* fila = origen;
    while (fila != nullptr) {
        Nodo* actual = fila;
        Nodo* siguienteFila = fila->abajo;
        while (actual != nullptr) {
            Nodo* siguiente = actual->derecha;
            delete actual;
            actual = siguiente;
        }
        fila = siguienteFila;
    }
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

Nodo* Mapa::nodoAleatorio() {
    Nodo* nodo = nullptr;
    do {
        int f = rand() % 9 + 1;
        int c = rand() % 9 + 1;
        nodo = origen;
        for (int i = 0; i < f; i++) nodo = nodo->abajo;
        for (int i = 0; i < c; i++) nodo = nodo->derecha;
    } while (nodo->contenido != 'o');
    return nodo;
}

void Mapa::colocarCallejones() {
    for (int i = 0; i < 16; i++) {
        Nodo* nodo = nodoAleatorio();
        nodo->contenido = '|';
    }
}

void Mapa::colocarPistas() {
    char tipos[4] = {'H', 'C', 'T', 'P'};
    for (int i = 0; i < 10; i++) {
        Nodo* nodo = nodoAleatorio();
        nodo->contenido = tipos[rand() % 4];
    }
}

void Mapa::colocarTestigos() {
    for (int i = 0; i < 5; i++) {
        Nodo* nodo = nodoAleatorio();
        nodo->contenido = 'W';
    }
}

void Mapa::imprimir() {
    Nodo* fila = origen;
    while (fila != nullptr) {
        Nodo* actual = fila;
        while (actual != nullptr) {
            if (!actual->descubierto &&
                actual->contenido != '#' &&
                actual->contenido != 'I') {
                cout << 'o' << " ";
            } else {
                cout << actual->contenido << " ";
            }
            actual = actual->derecha;
        }
        cout << "\n";
        fila = fila->abajo;
    }
}

void Mapa::taparMapa() {
    Nodo* fila = origen->abajo;
    while (fila != nullptr && fila->abajo != nullptr) {
        Nodo* actual = fila->derecha;
        while (actual != nullptr && actual->derecha != nullptr) {
            if (actual->contenido != 'I') {
                actual->descubierto = false;
                if (actual->contenido == ' ')
                    actual->contenido = 'o';
            }
            actual = actual->derecha;
        }
        fila = fila->abajo;
    }
}

void Mapa::reubicarDetective(Detective& detective) {
    // Limpiar la posicion actual del detective
    detective.posicionActual->contenido = ' ';
    detective.posicionActual->descubierto = true;

    // Tapar el mapa
    taparMapa();

    // Buscar nueva posicion valida y mover al detective
    Nodo* nuevaPos = nodoAleatorio();
    detective.posicionActual = nuevaPos;
    detective.posicionActual->contenido = 'I';
    detective.posicionActual->descubierto = true;

    cout << "La Prueba Forense te teletransporto a otra ubicacion.\n";
}

void Mapa::moverDetective(Detective& detective, char direccion,int& puntaje, int& pistasRecogidas, TablaHash& hash) {
    bool movioExitoso = detective.mover(direccion);

    if (!movioExitoso) return;

    puntaje++;

    char contenido = detective.posicionActual->contenido;
    detective.posicionActual->contenido = 'I';
    detective.posicionActual->descubierto = true;

    if (contenido == 'H' || contenido == 'C' ||
        contenido == 'T' || contenido == 'P') {
        cout << "¡Encontraste una pista! Tipo: " << contenido << "\n";
        // PERSONA 3: revelar atributo del culpable
        hash.revelarAtributo();
        detective.posicionActual->contenido = 'I';
    }

    if (contenido == 'W') {
        cout << "¡Hay un testigo aquí! Su declaración entra a la cola.\n";
        detective.posicionActual->contenido = 'I';
    }
}

void Mapa::eliminarCallejones(int cantidad) {
    // Recolecta todos los nodos con callejón
    Nodo* callejones[16];
    int total = 0;

    Nodo* fila = origen->abajo;
    while (fila != nullptr && fila->abajo != nullptr) {
        Nodo* actual = fila->derecha;
        while (actual != nullptr && actual->derecha != nullptr) {
            if (actual->contenido == '|')
                callejones[total++] = actual;
            actual = actual->derecha;
        }
        fila = fila->abajo;
    }

    if (total == 0) {
        cout << "  [Coartada] No hay callejones para eliminar.\n";
        return;
    }

    // Eliminar cantidad callejones aleatorios
    for (int i = 0; i < cantidad && total > 0; i++) {
        int idx = rand() % total;
        callejones[idx]->contenido = ' ';
        callejones[idx]->descubierto = true;
        // Quitar del arreglo para no repetir
        callejones[idx] = callejones[--total];
    }

    cout << "  [Coartada] Se eliminaron " << cantidad << " callejones.\n";
}