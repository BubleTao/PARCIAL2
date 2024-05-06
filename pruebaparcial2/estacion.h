#ifndef ESTACION_H
#define ESTACION_H

#include <string>
using namespace std;

class Estacion {
private:
    string nombre;
    int tiempoAnterior;
    bool esTransferencia;
    string nombreLinea;

public:
    Estacion(string _nombre, int _tiempoAnterior, bool _esTransferencia);
    string getNombre();
    int getTiempoAnterior();
    bool getEsTransferencia();
    string getNombreLinea();
};

#endif
