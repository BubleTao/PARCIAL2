#include "Nodo.h"


Nodo::Nodo(Estacion* _dato, Nodo* _siguiente) : dato(_dato), siguiente(_siguiente) {}

void Nodo::Reapuntador(Nodo* _siguiente)
{
    siguiente = _siguiente;
}
