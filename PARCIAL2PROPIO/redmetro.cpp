#include "redmetro.h"
#include <iostream>
using namespace std;

RedMetro::RedMetro() {}

void RedMetro::agregarLinea(Linea* linea) {
    lineas.push_back(linea);
}

void RedMetro::mostrarLineas() {
    cout << "Cantidad de lineas en la red: " << lineas.size() << endl;
}

vector<Linea*> RedMetro::getLineas() {
    return lineas;
}
