#ifndef MAPA_H
#define MAPA_H
#include "Nodo.h"
#include "Detective.h"
#include "TablaHash.h"
#include <cstdlib>
#include <ctime>

class Mapa {
public:
    Nodo* origen;
    void taparMapa();
    void reubicarDetective(Detective& detective);

    Mapa();
    ~Mapa();
    void imprimir();
    void eliminarCallejones(int cantidad);
    Nodo* nodoAleatorio();
    void moverDetective(Detective& detective, char direccion, 
                        int& puntaje, int& pistasRecogidas, 
                        TablaHash& hash);

private:
    void construir();
    void colocarCallejones();
    void colocarPistas();
    void colocarTestigos();
};
#endif