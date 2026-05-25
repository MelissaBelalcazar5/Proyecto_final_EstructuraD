//
// Created by Melissa Belalcazar on 25/05/26.
//

#include "Acusacion.h"
#include <iostream>
using namespace std;

void faseAcusacion(TablaHash& hash, int& puntaje) {

    cout << "\n";
    cout << "=========================================\n";
    cout << "  Has recolectado las 10 pistas.\n";
    cout << "  Es momento de acusar.\n";
    cout << "=========================================\n";

    // Mostrar tabla completa con atributos revelados
    hash.mostrarTodos(true);

    // Pedir nombre del acusado
    string nombre;
    cout << "\n¿A quien acusas? > ";
    cin >> nombre;

    // Búsqueda explícita O(1) en la hash
    cout << "\n  [Hash] Realizando busqueda O(1)...\n";
    Sospechoso* acusado = hash.buscar(nombre);

    if (acusado == nullptr) {
        cout << "\n  Sospechoso no encontrado en el registro.\n";
        cout << "  Caso cerrado como fracasado.\n";
        puntaje *= 2;
        cout << "  Puntaje penalizado: " << puntaje << " movimientos.\n";
        return;
    }

    if (acusado->esCulpable) {
        cout << "\n  ¡CASO RESUELTO!\n";
        cout << "  " << acusado->nombre << " era el culpable.\n";
        cout << "  Puntaje final: " << puntaje << " movimientos.\n";
    } else {
        cout << "\n  Acusacion incorrecta.\n";
        cout << "  El caso se cierra como fracasado.\n";
        puntaje *= 2;
        cout << "  Puntaje penalizado: " << puntaje << " movimientos.\n";

        // Revelar quién era el culpable real
        Sospechoso* culpable = hash.obtenerCulpable();
        if (culpable != nullptr)
            cout << "  El verdadero culpable era: " << culpable->nombre << "\n";
    }

    cout << "=========================================\n";
}