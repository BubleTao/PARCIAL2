#ifndef INTENTO_VECTOR_H
#define INTENTO_VECTOR_H
#include "estacion.h"
#include "Nodo.h"

class Intento_vector {
private:
    Nodo* cabeza;
    int size = 0;

public:
    Intento_vector();
    ~Intento_vector();
    void push_back(Estacion* element);
    void erase(int index);
    Estacion* operator[](int index);
    int getSize();
};

#endif
