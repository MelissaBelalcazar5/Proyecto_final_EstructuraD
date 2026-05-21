#pragma once
#include <string>

//  Clase Testigo representa un testigo ubicado en el tablero

class Testigo {
private:
    int fila; // coordenadas
    int columna; // coordenadas
    std::string declaracion;  // texto que dice el testigo
    bool yaDeclarado; // cambia a true cuando la declaración ya entró en la cola

public:
    Testigo(int f, int c, const std::string& decl);

    // Getters
    int         getFila()        const;
    int         getColumna()     const;
    std::string getDeclaracion() const;
    bool        isYaDeclarado()  const;
    std::string getSimbolo()     const;

    // Setters
    void setYaDeclarado(bool v);
    void setFila(int f);
    void setColumna(int c);

    void mostrar() const;
};