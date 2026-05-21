#include "Testigo.h"
#include <iostream>

Testigo::Testigo(int f, int c, const std::string& decl)
    : fila(f), columna(c), declaracion(decl), yaDeclarado(false) {}

// Getters
int Testigo::getFila() const { return fila; }
int Testigo::getColumna() const { return columna; }
std::string Testigo::getDeclaracion() const { return declaracion; }
bool Testigo::isYaDeclarado()  const { return yaDeclarado; }
std::string Testigo::getSimbolo() const { return "W"; }

// Setters
void Testigo::setYaDeclarado(bool v) { yaDeclarado = v; }
void Testigo::setFila(int f) { fila = f; }
void Testigo::setColumna(int c) { columna = c; }

void Testigo::mostrar() const {
    std::cout << "Testigo [W]"
              << " en (" << fila << ", " << columna << ")"
              << " | \"" << declaracion << "\""
              << (yaDeclarado ? " [declaro]" : " [pendiente]");
}