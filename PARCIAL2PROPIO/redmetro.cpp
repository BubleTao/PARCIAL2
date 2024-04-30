#include "redmetro.h"
#include <iostream>
using namespace std;

RedMetro::RedMetro() {}

RedMetro::~RedMetro() {
    // Liberar la memoria de todas las líneas en la red
    for (Linea* linea : lineas) {
        delete linea;
    }
    // Limpiar el vector de líneas
    lineas.clear();
}

void RedMetro::agregarLinea(Linea* linea) {
    lineas.push_back(linea);
}

void RedMetro::mostrarLineas() {
    cout << "Cantidad de lineas en la red: " << lineas.size() << endl;
}

vector<Linea*> RedMetro::getLineas() {
    return lineas;
}

int RedMetro::obtenerCantidadEstacionesLinea(string nombreLinea) {
    for (Linea* linea : lineas) {
        if (linea->getNombre() == nombreLinea) {
            return linea->obtenerCantidadEstaciones();
        }
    }
    return -1; // Retornar un valor negativo para indicar que la línea no existe
}

bool RedMetro::existeLinea(string nombreLinea) {
    for (Linea* linea : lineas) {
        if (linea->getNombre() == nombreLinea) {
            return true;
        }
    }
    return false;
}
