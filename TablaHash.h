//
// Created by Melissa Belalcazar on 19/05/26.
//

#ifndef PROYECTO_FINAL_ESTRUCTURAD_TABLAHASH_H
#define PROYECTO_FINAL_ESTRUCTURAD_TABLAHASH_H
#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <list>
#include <string>
#include <iostream>
#include "Sospechoso.h"
using namespace std;

class TablaHash {
private:
    static const int TAMANIO = 13;
    list<Sospechoso> tabla[TAMANIO];

    int funcionHash(string nombre);

public:
    void insertar(Sospechoso s);
    Sospechoso* buscar(string nombre);
    void mostrarTodos(bool soloRevelados = true);
    Sospechoso* obtenerCulpable();
};
#endif //PROYECTO_FINAL_ESTRUCTURAD_TABLAHASH_H