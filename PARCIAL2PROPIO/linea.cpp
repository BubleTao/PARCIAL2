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

void Linea::mostrarEstaciones() {
    cout << "Estaciones en la linea " << nombre << ":\n";
    for (Estacion* estacion : estaciones) {
        cout << "Nombre: " << estacion->getNombre() << ", ";
        cout << "Tiempo Siguiente: " << estacion->getTiempoSiguiente() << ", ";
        cout << "Tiempo Anterior: " << estacion->getTiempoAnterior() << ", ";
        cout << "Transferencia: " << (estacion->getEsTransferencia() ? "Si" : "No") << endl;
    }
}



