#include "linea.h"
#include <iostream>
using namespace std;

Linea::Linea(string _nombre, string _tipoTransporte) {
    nombre = _nombre;
    tipoTransporte = _tipoTransporte;
}

string Linea::getNombre() {
    return nombre;
}

void Linea::agregarEstacion(Estacion* estacion) {
    estaciones.push_back(estacion);
}

void Linea::eliminarEstacion(string nombreEstacion) {
    for (auto it = estaciones.begin(); it != estaciones.end(); ++it) {
        if ((*it)->getNombre() == nombreEstacion) {
            delete *it; // Liberar la memoria de la estación eliminada
            estaciones.erase(it);
            cout << "Estacion eliminada de la linea " << nombre << endl;
            return;
        }
    }
    cout << "La estacion no existe en esta linea.\n";
}

void Linea::mostrarEstaciones() {
    cout << "Estaciones en la linea " << nombre << ":\n";
    for (Estacion* estacion : estaciones) {
        cout << "Nombre: " << estacion->getNombre() << ", ";
        cout << "Tiempo Siguiente: " << estacion->getTiempoSiguiente() << ", ";
        cout << "Tiempo Anterior: " << estacion->getTiempoAnterior() << ", ";
        cout << "Transferencia: " << (estacion->getEsTransferencia() ? "Si" : "No") << endl;
    }
}



