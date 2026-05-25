//
// Created by Melissa Belalcazar on 25/05/26.
//

#include <iostream>
#include "Sospechoso.h"
#include "TablaHash.h"
#include "inicializar.h"
#include "Acusacion.h"
#include "abbPuntaje.h"
using namespace std;
//POR FAVOR LEAN LOS COMENTARIOS QUE AHI LES DEJE DONDE PONER Y QUIEN DEBE PONER LO QUE FALTA BASADO EN LO Q LE TOCA A CADA UNO 
int main() {

    // PERSONA 1: pide el nombre del detective al inicio
    string nombreDetective;
    cout << "========================================\n";
    cout << "   BIENVENIDO AL CASO DEL DETECTIVE\n";
    cout << "========================================\n";
    cout << "Ingresa tu nombre, detective: ";
    cin >> nombreDetective;

    TablaHash hash;
    inicializarSospechosos(hash);
    ABBPuntajes arbol;
    int puntaje = 0;
    int pistasRecogidas = 0; // PERSONA 2 actualiza esta variable

    // LOOP PRINCIPAL DEL JUEGO
    char tecla;
    bool juegoActivo = true;

    while (juegoActivo) {

        // PERSONA 1: imprime el tablero aquí
        // mapa.imprimir();

        cout << "\n" << nombreDetective << ", Tu puntaje actual es: " << puntaje << "\n";
        cout << "> ";
        cin >> tecla;
        tecla = toupper(tecla);

        if (tecla == 'W' || tecla == 'A' || tecla == 'S' || tecla == 'D') {
            // PERSONA 1: maneja movimiento y actualiza puntaje y pistasRecogidas
            // mapa.moverDetective(tecla, puntaje, pistasRecogidas, hash);

        } else if (tecla == 'T') {
            // PERSONA 2: muestra la pila de pistas
            // pilaPistas.mostrar();

        } else if (tecla == 'S') {
            hash.mostrarTodos(true);

        } else if (tecla == 'I') {
            // PERSONA 2: interroga al siguiente testigo
            // colaTestigos.interrogar(hash);

        } else if (tecla == 'X') {
            // PERSONA 2: usa la última pista
            // pilaPistas.usarPista(puntaje, mapa, hash);

        }

        // CUANDO EL DETECTIVE RECOGE LA PISTA 10:
        if (pistasRecogidas >= 10)
            juegoActivo = false;
    }

    // FASE DE ACUSACIÓN
    faseAcusacion(hash, puntaje);

    // GUARDAR PUNTAJE EN EL ABB
    arbol.guardar(nombreDetective, puntaje);

    // VER RANKING
    arbol.mostrarRanking();

    // BUSCAR DETECTIVE
    int puntajeGuardado;
    if (arbol.buscar(nombreDetective, puntajeGuardado))
        cout << "Mejor puntaje de " << nombreDetective << ": " << puntajeGuardado << "\n";
    else
        cout << nombreDetective << " no tiene puntaje registrado.\n";

    return 0;
}