#ifndef LINEA_H
#define LINEA_H

#include <string>
#include <vector>
#include "estacion.h"
using namespace std;

class Linea {
private:
    string nombre;
    string tipoTransporte;
    vector<Estacion*> estaciones;

public:
    Linea(string _nombre, string _tipoTransporte);
    string getNombre();
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string nombreEstacion);
    void mostrarEstaciones();
};

#endif
