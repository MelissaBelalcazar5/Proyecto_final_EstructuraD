//
// Created by Melissa Belalcazar on 19/05/26.
//

#include "inicializar.h"

void inicializarSospechosos(TablaHash& hash) {
    vector<Sospechoso> candidatos = {
        {"Carlos",   "alto",    "negro",   "clara",  "afilada",    "masculino", "zurdo"},
        {"Diana",    "alta",    "rubio",   "clara",  "respingada", "femenino",  "diestra"},
        {"Eduardo",  "mediano", "castano", "morena", "ancha",      "masculino", "diestro"},
        {"Fernanda", "alta",    "rojo",    "clara",  "respingada", "femenino",  "diestra"},
        {"Gonzalo",  "bajo",    "negro",   "oscura", "ancha",      "masculino", "diestro"},
        {"Hilda",    "alta",    "rubio",   "clara",  "afilada",    "femenino",  "zurda"},
        {"Ivan",     "alto",    "castano", "morena", "ancha",      "masculino", "diestro"},
        {"Julia",    "baja",    "negro",   "oscura", "respingada", "femenino",  "zurda"},
        {"Kevin",    "alto",    "rubio",   "clara",  "afilada",    "masculino", "diestro"},
        {"Laura",    "mediana", "rojo",    "morena", "ancha",      "femenino",  "diestra"},
        {"Marcos",   "bajo",    "negro",   "clara",  "respingada", "masculino", "zurdo"},
        {"Nina",     "alta",    "castano", "oscura", "afilada",    "femenino",  "diestra"},
    };

    srand(time(0));

    //SE ENCARGA DE MEZCLAR LOS CANDIDATOS
    for (int i = candidatos.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(candidatos[i], candidatos[j]);
    }

    //SE ENCARGA DE MARCAR EL CULPABLE COMPLETAMENTE ALEATORIO
    int indiceCulpable = rand() % 8;
    candidatos[indiceCulpable].esCulpable = true;

    //INSERTA LOS PRIMEROS 8 CANDIDATOS
    for (int i = 0; i < 8; i++)
        hash.insertar(candidatos[i]);
}