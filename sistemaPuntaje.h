#ifndef PROYECTO_FINAL_ESTRUCTURAD_SISTEMAPUNTAJE_H
#define PROYECTO_FINAL_ESTRUCTURAD_SISTEMAPUNTAJE_H

#pragma once
#include <string>

//  CLase: sistemaPuntaje. Maneja el puntaje del detective durante la partida
class sistemaPuntaje {
private:
    int puntaje;

public:
    sistemaPuntaje();

    int  getPuntaje() const;
    void setPuntaje(int v);

    void registrarMovimiento();
    void aplicarHuella();
    void aplicarTestimonio();
    void penalizarAcusacion();

    void mostrar(const std::string& nombreDetective) const;
};


#endif //PROYECTO_FINAL_ESTRUCTURAD_SISTEMAPUNTAJE_H
