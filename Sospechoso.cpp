//
// Created by Melissa Belalcazar on 19/05/26.
//

#include "Sospechoso.h"

Sospechoso::Sospechoso() : esCulpable(false) {}

Sospechoso::Sospechoso(string nom, string est, string cab, string pie,
                       string nar, string sex, string man)
    : nombre(nom), estatura(est), cabello(cab), piel(pie),
      nariz(nar), sexo(sex), mano(man), esCulpable(false) {}

string Sospechoso::obtenerSiguienteAtributo() {
    vector<string> todos = {estatura, cabello, piel, nariz, sexo, mano};
    if (atributosRevelados.size() < todos.size())
        return todos[atributosRevelados.size()];
    return "";
}