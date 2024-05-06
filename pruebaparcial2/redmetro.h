#ifndef REDMETRO_H
#define REDMETRO_H

#include "linea.h"
using namespace std;

class RedMetro {
private:

    int tamano = 0;

public:
    Linea* cabeza = nullptr;
    RedMetro();
    ~RedMetro();
    void agregarLinea(Linea* linea);
    void eliminarLinea(string nombreLinea);
    void mostrarLineas();
    Linea* pertenece(string);
    int obtenerCantidadEstacionesLinea(string nombreLinea);
    bool existeLinea(string nombreLinea);
    Linea* obtenerPrimeraLinea();
    Linea* obtenerSiguienteLinea(Linea* lineaActual);

};

#endif
