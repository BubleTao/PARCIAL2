#ifndef ESTACION_H
#define ESTACION_H

#include <string>
using namespace std;

class Estacion {
private:
    string nombre;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool esTransferencia;
    string nombreLinea;

public:
    Estacion(string _nombre, int _tiempoSiguiente, int _tiempoAnterior, bool _esTransferencia);
    string getNombre();
    int getTiempoSiguiente();
    int getTiempoAnterior();
    bool getEsTransferencia();
    string getNombreLinea();
};

#endif
