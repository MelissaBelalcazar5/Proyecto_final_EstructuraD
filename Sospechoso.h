//
// Created by Melissa Belalcazar on 19/05/26.
//

#ifndef PROYECTO_FINAL_ESTRUCTURAD_SOSPECHOSO_H
#define PROYECTO_FINAL_ESTRUCTURAD_SOSPECHOSO_H
#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include <string>
#include <vector>
using namespace std;

class Sospechoso {
public:
    string nombre;
    string estatura;
    string cabello;
    string piel;
    string nariz;
    string sexo;
    string mano;
    bool esCulpable;
    vector<string> atributosRevelados;

    Sospechoso();
    Sospechoso(string nom, string est, string cab, string pie,
               string nar, string sex, string man);

    string obtenerSiguienteAtributo();
};
#endif //PROYECTO_FINAL_ESTRUCTURAD_SOSPECHOSO_H