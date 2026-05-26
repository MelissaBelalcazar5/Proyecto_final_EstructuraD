#include <iostream>
#include "Testigo.h"
#include "Pista.h"
#include "PilaPistas.h"
#include "ColaTestigos.h"
#include "sistemaPuntaje.h"
#include "abbPuntaje.h"
#include "Sospechoso.h"
#include "TablaHash.h"
#include "inicializar.h"
#include "Acusacion.h"
#include "Mapa.h"
#include "Detective.h"
using namespace std;

// Devuelve el nodo al que se movería el detective según la dirección, sin moverlo.
Nodo* nodoDestino(Detective& detective, char direccion) {
    if (direccion == 'W') return detective.posicionActual->arriba;
    if (direccion == 'S') return detective.posicionActual->abajo;
    if (direccion == 'A') return detective.posicionActual->izquierda;
    if (direccion == 'D') return detective.posicionActual->derecha;
    return nullptr;
}

// Limpiar pantalla
void limpiarPantalla() {
//    cout << string(50, '\n');
    return;
}

// Muestra los controles disponibles
void mostrarControles() {
    cout << "[T] Ver pistas  [I] Interrogar testigo  [S] Sospechosos  [X] Usar pista\n";
}

int main() {
    // Pide el nombre del detective al inicio
    limpiarPantalla();
    cout << "========================================\n";
    cout << "   BIENVENIDO AL CASO DEL DETECTIVE\n";
    cout << "========================================\n";
    cout << "Ingresa tu nombre, detective: ";
    string nombreDetective;
    cin >> nombreDetective;

    // Verificar si ya jugó antes
    ABBPuntajes arbol;
    int puntajeAnterior;
    if (arbol.buscar(nombreDetective, puntajeAnterior))
        cout << "Ya jugaste antes. Tu mejor puntaje: " << puntajeAnterior << "\n\n";

    // Inicializar estructuras
    TablaHash hash;
    inicializarSospechosos(hash);

    PilaPistas pilaPistas;
    ColaTestigos colaTestigos;

    sistemaPuntaje puntaje;
    int pistasRecogidas = 0;

    // Crear mapa y detective
    Mapa mapa;
    Nodo* posInicial = mapa.nodoAleatorio();
    Detective detective(nombreDetective, posInicial);

    // Pool de pistas para poder hacer push con objetos Pista reales
    Pista* pistaPool[10];
    int totalPistasCreadas = 0;

    // Pool de testigos (máximo 5)
    Testigo* testigoPool[5];
    int totalTestigosCreados = 0;

    // LOOP PRINCIPAL DEL JUEGO
    char tecla;
    bool juegoActivo = true;

    while (juegoActivo) {

        // Limpiar pantalla
        limpiarPantalla();
        // Imprime el tablero
        mapa.imprimir();

        cout << "\n";
        puntaje.mostrar(nombreDetective);
        cout << "Pistas recogidas: " << pistasRecogidas << "/10";
        cout << "  |  Testigos en cola: " << colaTestigos.getTam() << "\n";
        mostrarControles();
        cout << "> ";
        cin >> tecla;
        tecla = toupper(tecla);

        if (tecla == 'W' || tecla == 'A' || tecla == 'S' || tecla == 'D') {
            // PERSONA 1: maneja movimiento
            Nodo* destino = nodoDestino(detective, tecla);
            char contenidoAntes = (destino != nullptr) ? destino->contenido : ' ';

            cout << "DEBUG contenidoAntes: [" << contenidoAntes << "]\n";

            // Ejecutar movimiento
            int p = puntaje.getPuntaje();
            mapa.moverDetective(detective, tecla, p, pistasRecogidas, hash);
            puntaje.setPuntaje(p);

            // Actua según lo que haya en destino
            if (destino != nullptr) {
                char contenido = destino->contenido;

                // Pista recogida
                if (contenidoAntes == 'H' || contenidoAntes == 'C' || contenidoAntes == 'T' || contenidoAntes == 'P') {

                    TipoPista tipo;
                    if (contenido == 'H') tipo = TipoPista::HUELLA;
                    else if (contenido == 'C') tipo = TipoPista::COARTADA;
                    else if (contenido == 'T') tipo = TipoPista::TESTIMONIO;
                    else tipo = TipoPista::PRUEBA_FORENSE;

                    Pista* nuevaPista = new Pista(tipo, destino->fila, destino->col);
                    nuevaPista->setRecogida(true);
                    pistaPool[totalPistasCreadas++] = nuevaPista;
                    pilaPistas.push(nuevaPista);
                    pistasRecogidas++;

                    cout << "\n  ¡Encontraste una pista tipo [" << nuevaPista->getSimbolo() << "]!\n";
                    pilaPistas.mostrarVisual(nombreDetective);
                    }

                // Testigo pisado
                if (contenidoAntes == 'W') {
                    // Crear testigo con declaración genérica (P3 revela el atributo real)
                    Testigo* t = new Testigo(destino->fila, destino->col,"Tengo informacion sobre el caso");
                    colaTestigos.queue(t);
                }
            }

        // Ver pila de pistas
        } else if (tecla == 'T') {
            limpiarPantalla();
            pilaPistas.mostrarVisual(nombreDetective);
            cout << "\nPresiona Enter para continuar...";
            cin.ignore(); cin.get();

        // ver sospechosos
        } else if (tecla == 'S') {
            limpiarPantalla();
            hash.mostrarTodos(true);
            cout << "\nPresiona Enter para continuar...";
            cin.ignore(); cin.get();

        // interrogar al siguiente testigo
        } else if (tecla == 'I') {
            if (colaTestigos.estaVacia()) {
                cout << "No hay testigos en la cola.\n";
                cout << "Presiona Enter para continuar...";
                cin.ignore(); cin.get();
            } else {
                Testigo* t = colaTestigos.unqueue();
                cout << "Interrogando a testigo en (" << t->getFila() << ", " << t->getColumna() << ")...\n";
                // P3: revelar atributo del culpable
                hash.revelarAtributo();
                cout << "Presiona Enter para continuar...";
                cin.ignore(); cin.get();
            }

        // usar ultima pista
        } else if (tecla == 'X') {
            if (pilaPistas.estaVacia()) {
                cout << "No tienes pistas para usar.\n";
                cout << "Presiona Enter para continuar...";
                cin.ignore(); cin.get();
            } else {
                Pista* usada = pilaPistas.pop();
                cout << "Usando pista: " << usada->getSimbolo() << "\n";

                switch (usada->getTipo()) {
                    case TipoPista::HUELLA:
                        puntaje.aplicarHuella();
                        break;

                    case TipoPista::COARTADA:
                        mapa.eliminarCallejones(2);
                        cout << "[Coartada] Se eliminaron 2 callejones.\n";
                        break;

                    case TipoPista::TESTIMONIO:
                        puntaje.aplicarTestimonio();
                        break;

                    case TipoPista::PRUEBA_FORENSE:
                        mapa.reubicarDetective(detective);
                        break;
                }

                // Tapar mapa y reubicar la pista usada
                mapa.taparMapa();
                // recolocarPista(mapa, usada);
                usada->setRecogida(false);
                pistasRecogidas--;
                cout << "La pista [" << usada->getSimbolo() << "] volvio al mapa.\n";
                cout << "Presiona Enter para continuar...";
                cin.ignore(); cin.get();

            }
        }

        // Verificar fin de juego
        if (pistasRecogidas >= 10)
            juegoActivo = false;
    }

    // FASE DE ACUSACIÓN
    limpiarPantalla();
    int pf = puntaje.getPuntaje();
    faseAcusacion(hash, pf);
    puntaje.setPuntaje(pf);

    // GUARDAR PUNTAJE EN EL ABB
    arbol.guardar(nombreDetective, puntaje.getPuntaje());
    // VER RANKING
    arbol.mostrarRanking();

    // BUSCAR DETECTIVE
    int puntajeGuardado;
    if (arbol.buscar(nombreDetective, puntajeGuardado))
        cout << "Mejor puntaje de " << nombreDetective << ": " << puntajeGuardado << "\n";
    else
        cout << nombreDetective << " no tiene puntaje registrado.\n";

    // Liberar memoria
    for (int i = 0; i < totalPistasCreadas; i++) delete pistaPool[i];
    for (int i = 0; i < totalTestigosCreados; i++) delete testigoPool[i];

    return 0;
}