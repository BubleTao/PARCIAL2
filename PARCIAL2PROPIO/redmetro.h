#ifndef REDMETRO_H
#define REDMETRO_H

#include <vector>
#include "linea.h"
using namespace std;

class RedMetro {
private:
    vector<Linea*> lineas;

public:
    RedMetro();
    ~RedMetro();
    void agregarLinea(Linea* linea);
    void eliminarLinea(string nombreLinea);
    void mostrarLineas();
    vector<Linea*> getLineas(); // Declaración del método público
    int obtenerCantidadEstacionesLinea(string nombreLinea); // Nuevo método para obtener cantidad de estaciones de una línea
    bool existeLinea(string nombreLinea);
};

#endif

