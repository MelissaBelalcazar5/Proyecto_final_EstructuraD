//
// Created by Melissa Belalcazar on 19/05/26.
//

#include "TablaHash.h"

int TablaHash::funcionHash(string nombre) {
    int suma = 0;
    for (char c : nombre)
        suma += (int)c;
    return suma % TAMANIO;
}

void TablaHash::insertar(Sospechoso s) {
    int indice = funcionHash(s.nombre);
    tabla[indice].push_back(s);
}

Sospechoso* TablaHash::buscar(string nombre) {
    int indice = funcionHash(nombre);
    cout << "  [Hash] Buscando en indice " << indice << "...\n";
    for (auto& s : tabla[indice]) {
        if (s.nombre == nombre)
            return &s;
    }
    return nullptr;
}

void TablaHash::mostrarTodos(bool soloRevelados) {
    cout << "\n=== SOSPECHOSOS DEL CASO ===\n";
    for (int i = 0; i < TAMANIO; i++) {
        for (auto& s : tabla[i]) {
            cout << "  " << s.nombre;
            if (soloRevelados) {
                cout << "atributos confirmados: ";
                if (s.atributosRevelados.empty())
                    cout << "-";
                for (auto& a : s.atributosRevelados)
                    cout << a << "  ";
            }
            cout << "\n";
        }
    }
    cout << "============================\n";
}

Sospechoso* TablaHash::obtenerCulpable() {
    for (int i = 0; i < TAMANIO; i++)
        for (auto& s : tabla[i])
            if (s.esCulpable)
                return &s;
    return nullptr;
}
void TablaHash::revelarAtributo() {
    Sospechoso* culpable = obtenerCulpable();
    if (culpable == nullptr) return;

    string atributo = culpable->obtenerSiguienteAtributo();
    if (atributo.empty()) {
        cout << "Ya se revelaron todos los atributos del culpable.\n";
        return;
    }

    culpable->atributosRevelados.push_back(atributo);

    cout << "\n  >> Nuevo dato del culpable revelado: " << atributo << "\n";
}