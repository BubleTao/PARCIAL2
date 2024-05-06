#include "estacion.h"

Estacion::Estacion(string _nombre, int _tiempoAnterior, bool _esTransferencia) {
    nombre = _nombre;
    tiempoAnterior = _tiempoAnterior;
    esTransferencia = _esTransferencia;
}

string Estacion::getNombre() {
    return nombre;
}

int Estacion::getTiempoAnterior() {
    return tiempoAnterior;
}

bool Estacion::getEsTransferencia() {
    return esTransferencia;
}

string Estacion::getNombreLinea() {
    return nombreLinea;
}
