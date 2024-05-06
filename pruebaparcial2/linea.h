#ifndef LINEA_H
#define LINEA_H

#include <string>
#include "intento_vector.h"
#include "estacion.h"
using namespace std;

class Linea {
private:
    string nombre;
    Intento_vector* estaciones;
    Linea* siguiente = nullptr;

public:
    Linea* getsiguiente();
    void reroute(Linea*);
    Linea(string _nombre);
    string getNombre();
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string nombreEstacion);
    void mostrarEstaciones();
    int obtenerCantidadEstaciones();
    Estacion* buscarEstacion(string nombreEstacion);
};

#endif
