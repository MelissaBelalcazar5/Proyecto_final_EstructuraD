#ifndef PISTA_H
#define PISTA_H
#pragma once
#include <string>

//  tipos de pista
enum class TipoPista {
    HUELLA, // "H"
    COARTADA, // "C"
    TESTIMONIO, // "T"
    PRUEBA_FORENSE // "P"
};

std::string tipoPistaToString(TipoPista t);

//  Clase Pista
//  Representa una pista oculta en el tablero.
class Pista {
private:
    TipoPista tipo; // tipo de pista
    int       fila; // coordenada
    int       columna; // coordenada
    bool      recogida; // cambia a true cuando fue recogida por el usuario

public:
    Pista(TipoPista t, int f, int c);

    // Getters
    TipoPista   getTipo()    const;
    int         getFila()    const;
    int         getColumna() const;
    bool        isRecogida() const;
    std::string getSimbolo() const;  // ítem 12

    // Setters
    void setRecogida(bool v);
    void setFila(int f);
    void setColumna(int c);

    void mostrar() const;
};
#endif
