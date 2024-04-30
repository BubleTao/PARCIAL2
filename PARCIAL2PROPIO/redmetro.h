#ifndef REDMETRO_H
#define REDMETRO_H

#include <vector>
#include "linea.h"
using namespace std;

class RedMetro {
private:
    vector<Linea*> lineas;

public:
    RedMetro();
    void agregarLinea(Linea* linea);
    void mostrarLineas();
};

#endif

