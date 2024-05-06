#include "Linea.h"
#include <iostream>
using namespace std;

Linea *Linea::getsiguiente()
{
    return siguiente;
}

void Linea::reroute(Linea * Linea)
{
    siguiente = Linea;
}

Linea::Linea(string _nombre) : nombre(_nombre){
    estaciones = new Intento_vector();
}

string Linea::getNombre() {
    return nombre;
}

void Linea::agregarEstacion(Estacion* estacion) {
    estaciones->push_back(estacion);

}

void Linea::eliminarEstacion(string nombreEstacion) {
    auto index = 0;
    while (index < estaciones->getSize()) {
        Estacion* estacion = (*estaciones)[index];
        if (estacion->getNombre() == nombreEstacion) {
            if (estacion->getEsTransferencia()) {
                cout << "No se puede eliminar una estacion de transferencia.\n";
                return;
            }
            estaciones->erase(index);
            cout << "Estacion eliminada de la linea " << nombre << endl;
            return;
        } else {
            ++index;
        }
    }
    cout << "La estacion no existe en esta linea.\n";
}

void Linea::mostrarEstaciones() {
    cout << "Estaciones en la linea " << nombre << ":\n";
    for (int i = 0; i < estaciones->getSize(); ++i) {
        Estacion* estacion = (*estaciones)[i];
        cout << "Nombre: " << estacion->getNombre() << ", ";
        cout << "Tiempo Anterior: " << estacion->getTiempoAnterior() << ", ";
        cout << "Transferencia: " << (estacion->getEsTransferencia() ? "Si" : "No") << endl;
    }
}

int Linea::obtenerCantidadEstaciones() {
    return estaciones->getSize();// Usa el método getSize de IntentoVector
}

Estacion* Linea::buscarEstacion(string nombreEstacion) {
    for (int i = 0; i < estaciones->getSize(); ++i) {
        Estacion* estacion = (*estaciones)[i];
        if (estacion->getNombre() == nombreEstacion) {
            return estacion;
        }
    }
    return nullptr; // Retornar nullptr si no se encuentra la estación
}

