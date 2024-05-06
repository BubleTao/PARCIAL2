#ifndef NODO_H
#define NODO_H
#include "estacion.h"
class Nodo {
public:
    Estacion* dato;
    Nodo* siguiente;
    Nodo(Estacion* _dato, Nodo* _siguiente = nullptr);
    void Reapuntador(Nodo* _siguiente);
};

#endif
