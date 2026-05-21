#pragma once
#include <string>
#include <iostream>

//  tipos de pista
enum class TipoPista {
    HUELLA, // "H"
    COARTADA, // "C"
    TESTIMONIO, // "T"
    PRUEBA_FORENSE // "P"
};

inline std::string tipoPistaToString(TipoPista t) {
    switch (t) {
        case TipoPista::HUELLA: return "H";
        case TipoPista::COARTADA: return "C";
        case TipoPista::TESTIMONIO: return "T";
        case TipoPista::PRUEBA_FORENSE: return "P";
    }
    return "?";
}

//  Clase pista: Representa una pista oculta en el tablero.

class Pista {
private:
    TipoPista tipo; // tipo de pista
    int fila; // coordenada
    int columna; // coordenada
    bool recogida;   // cambia a true cuando fue recodiga por el usuario

public:
    // Constructor
    Pista(TipoPista t, int f, int c)
        : tipo(t), fila(f), columna(c), recogida(false) {}

    // Getters
    TipoPista getTipo() const { return tipo; }
    int getFila() const { return fila; }
    int getColumna() const { return columna; }
    bool isRecogida() const { return recogida; }

    // Setters
    void setRecogida(bool v) { recogida = v; }
    void setFila(int f) { fila = f; }
    void setColumna(int c) { columna = c; }

    // Símbolo que se muestra en el tablero al descubrirse
    std::string getSimbolo() const { return tipoPistaToString(tipo); }

    // función mostrar
    void mostrar() const {
        std::cout << "Pista [" << tipoPistaToString(tipo) << "]"
                  << " en (" << fila << ", " << columna << ")"
                  << (recogida ? " [RECOGIDA]" : " [en mapa]");
    }
};