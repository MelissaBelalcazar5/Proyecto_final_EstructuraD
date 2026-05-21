#include "Pista.h"
#include <iostream>

std::string tipoPistaToString(TipoPista t) {
    switch (t) {
        case TipoPista::HUELLA: return "H";
        case TipoPista::COARTADA: return "C";
        case TipoPista::TESTIMONIO: return "T";
        case TipoPista::PRUEBA_FORENSE:return "P";
    }
    return "?";
}

Pista::Pista(TipoPista t, int f, int c)
    : tipo(t), fila(f), columna(c), recogida(false) {}

// Getters
TipoPista   Pista::getTipo()    const { return tipo; }
int         Pista::getFila()    const { return fila; }
int         Pista::getColumna() const { return columna; }
bool        Pista::isRecogida() const { return recogida; }

std::string Pista::getSimbolo() const { return tipoPistaToString(tipo); }

// Setters
void Pista::setRecogida(bool v) { recogida = v; }
void Pista::setFila(int f) { fila = f; }
void Pista::setColumna(int c) { columna = c; }

void Pista::mostrar() const {
    std::cout << "Pista [" << tipoPistaToString(tipo) << "]"
              << " en (" << fila << ", " << columna << ")"
              << (recogida ? " [RECOGIDA]" : " [en mapa]");
}