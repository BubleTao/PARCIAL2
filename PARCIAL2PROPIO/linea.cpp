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
    auto it = estaciones.begin();
    while (it != estaciones.end()) {
        if ((*it)->getNombre() == nombreEstacion) {
            if ((*it)->getEsTransferencia()) {
                cout << "No se puede eliminar una estacion de transferencia.\n";
                return;
            }
            delete *it; // Liberar la memoria de la estación eliminada
            it = estaciones.erase(it); // Actualizar el iterador después de la eliminación
            cout << "Estacion eliminada de la linea " << nombre << endl;
            return;
        } else {
            ++it;
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

int Linea::obtenerCantidadEstaciones() {
    return estaciones.size();
}

Estacion* Linea::buscarEstacion(string nombreEstacion) {
    for (Estacion* estacion : estaciones) {
        if (estacion->getNombre() == nombreEstacion) {
            return estacion;
        }
    }
    return nullptr; // Retornar nullptr si no se encuentra la estación
}


