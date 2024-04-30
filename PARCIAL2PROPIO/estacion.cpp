#include "estacion.h"

Estacion::Estacion(string _nombre, int _tiempoSiguiente, int _tiempoAnterior, bool _esTransferencia) {
    nombre = _nombre;
    tiempoSiguiente = _tiempoSiguiente;
    tiempoAnterior = _tiempoAnterior;
    esTransferencia = _esTransferencia;
}

string Estacion::getNombre() {
    return nombre;
}

int Estacion::getTiempoSiguiente() {
    return tiempoSiguiente;
}

int Estacion::getTiempoAnterior() {
    return tiempoAnterior;
}

bool Estacion::getEsTransferencia() {
    return esTransferencia;
}
