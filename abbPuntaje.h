#ifndef ABBPUNTAJE_H
#define ABBPUNTAJE_H
#include <string>

//  Nodo interno del Arbol binario de busqueda
struct NodoABB {
    std::string nombre;
    int mejorPuntaje;
    NodoABB* izquierdo;
    NodoABB* derecho;

    NodoABB(const std::string& n, int p);
};


//  Clase Arbol Binario de Búsqueda
//  Clave de inserción: puntaje (menor a la izquierda)
//  Así el recorrido inorden da orden de menor a mayor
class ABBPuntajes {
private:
    NodoABB* raiz;

    // Recursivas
    NodoABB* insertarRec(NodoABB* nodo, const std::string& nombre, int puntaje);
    NodoABB* buscarPorNombreRec(NodoABB* nodo, const std::string& nombre) const;
    void inordenRec(NodoABB* nodo) const;
    void destruirRec(NodoABB* nodo);

public:
    ABBPuntajes();
    ~ABBPuntajes();

    ABBPuntajes(const ABBPuntajes&) = delete;
    ABBPuntajes& operator = (const ABBPuntajes&) = delete;

    void guardar(const std::string& nombre, int puntaje);
    bool buscar(const std::string& nombre, int& puntajeOut) const;
    void mostrarRanking() const;
};

#endif //PROYECTO_FINAL_ESTRUCTURAD_ABBPUNTAJE_H
