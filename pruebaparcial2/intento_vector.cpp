#include "Intento_vector.h"

Intento_vector::Intento_vector() : cabeza(nullptr), size(0) {}

Intento_vector::~Intento_vector() {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void Intento_vector::push_back(Estacion* element) {
    Nodo* inicial = cabeza;
    Nodo* anterior = nullptr;
    bool bandera= 1;
    while(bandera){
        if (inicial == nullptr){
            if (size==0){
                cabeza=new Nodo(element);
            }
            else {
                anterior->Reapuntador(new Nodo(element));
            }
            size++;
            bandera=0;
        }
        else{
        anterior = inicial;
        inicial = inicial-> siguiente;

        }
    }

}

void Intento_vector::erase(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    if (index == 0) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    } else {
        Nodo* temp = cabeza;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->siguiente;
        }
        Nodo* nodoAEliminar = temp->siguiente;
        temp->siguiente = nodoAEliminar->siguiente;
        delete nodoAEliminar;
    }
    size--;
}

Estacion* Intento_vector::operator[](int index) {
    Nodo* temp = cabeza;
    for (int i = 0; i < index; ++i) {
        temp = temp->siguiente;
    }
    return temp->dato;
}

int Intento_vector::getSize() {
    return size;
}

