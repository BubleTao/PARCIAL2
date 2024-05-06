#ifndef REDMETRO_H
#define REDMETRO_H

#include "linea.h"
using namespace std;

class RedMetro {
private:
    Linea* cabeza = nullptr;
    int tamano = 0;

public:
    RedMetro();
    ~RedMetro();
    void agregarLinea(Linea* linea);
    void eliminarLinea(string nombreLinea);
    void mostrarLineas();
    Linea* pertenece(string);
    int obtenerCantidadEstacionesLinea(string nombreLinea); // Nuevo método para obtener cantidad de estaciones de una línea
    bool existeLinea(string nombreLinea);
};

#endif
