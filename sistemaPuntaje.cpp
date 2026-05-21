#include "sistemaPuntaje.h"
#include <iostream>
#include <cstdlib>

sistemaPuntaje::sistemaPuntaje() : puntaje(0) {}

int sistemaPuntaje::getPuntaje() const {
    return puntaje;
}

void sistemaPuntaje::setPuntaje(int v) {
    puntaje = v;
}

// Función de suma: cada movimiento suma 1 punto
void sistemaPuntaje::registrarMovimiento() {
    puntaje++;
}

// Efecto de Huella: puntaje se reduce a la mitad
void sistemaPuntaje::aplicarHuella() {
    puntaje = puntaje / 2;
    std::cout << "  [Huella] Tu puntaje se redujo a la mitad: "
              << puntaje << "\n";
}

// Efecto de Testimonio: 50% resetea a 0, 50% duplica
void sistemaPuntaje::aplicarTestimonio() {
    if (rand() % 2 == 0) {
        puntaje = 0;
        std::cout << "  [Testimonio] Tuviste suerte! Puntaje reseteado a 0.\n";
    } else {
        puntaje *= 2;
        std::cout << "  [Testimonio] Mala suerte. Puntaje duplicado: "
                  << puntaje << "\n";
    }
}

// Efecto de acusacion incorrecta: puntaje se duplica
void sistemaPuntaje::penalizarAcusacion() {
    puntaje *= 2;
    std::cout << "  [Acusacion fallida] Puntaje penalizado al doble: "
              << puntaje << "\n";
}

void sistemaPuntaje::mostrar(const std::string& nombreDetective) const {
    std::cout << nombreDetective
              << ", Tu puntaje actual es: " << puntaje << "\n";
}