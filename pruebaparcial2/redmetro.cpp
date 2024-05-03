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

void RedMetro::eliminarLinea(string nombreLinea) {
    auto it = lineas.begin();
    while (it != lineas.end()) {
        if ((*it)->getNombre() == nombreLinea) {
            // Verificar si la línea tiene estaciones
            int cantidadEstaciones = (*it)->obtenerCantidadEstaciones();
            if (cantidadEstaciones > 0) {
                cout << "No se puede eliminar la linea porque tiene estaciones.\n";
                return;
            } else {
                delete *it; // Liberar la memoria de la línea eliminada
                it = lineas.erase(it); // Actualizar el iterador después de la eliminación
                cout << "Linea eliminada de la red Metro.\n";
                return;
            }
        } else {
            ++it;
        }
    }
    cout << "La linea no existe en la red Metro.\n";
}
