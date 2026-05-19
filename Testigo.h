#pragma once
#include <string>
#include <iostream>

// =======================================================
//  Clase testigo
//  Representa un testigo ubicado en el tablero (ítem 17)
// =======================================================

class Testigo {
private:
    int         fila; // Coordenadas
    int         columna; // Coordenadas
    std::string declaracion;  // Texto que dice el testigo
    bool        yaDeclarado;  // cambia a true cuando la declaración ya entró en la cola

public:
    // Constructor
    Testigo(int f, int c, const std::string& decl) : fila(f), columna(c), declaracion(decl), yaDeclarado(false) {}

    // Getters
    int         getFila()       const { return fila; }
    int         getColumna()    const { return columna; }
    std::string getDeclaracion()const { return declaracion; }
    bool        isYaDeclarado() const { return yaDeclarado; }

    // Setters 
    void setYaDeclarado(bool v) { yaDeclarado = v; }
    void setFila(int f)         { fila = f; }
    void setColumna(int c)      { columna = c; }

    // Símbolo en el tablero (ítem 17)
    std::string getSimbolo() const { return "W"; }

    // función mostrar
    void mostrar() const {
        std::cout << "Testigo [W]"
                  << " en (" << fila << ", " << columna << ")"
                  << " | \"" << declaracion << "\""
                  << (yaDeclarado ? " [declaró]" : " [pendiente]");
    }
};