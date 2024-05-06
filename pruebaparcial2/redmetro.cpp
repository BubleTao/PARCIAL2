#include "redmetro.h"
#include <iostream>
using namespace std;

RedMetro::RedMetro() {}

RedMetro::~RedMetro() {
    Linea* nuevo= cabeza;
    Linea* paso= nullptr;
    while (nuevo->getsiguiente()!=nullptr){
        paso=nuevo;
        nuevo=nuevo->getsiguiente();
        delete paso;
    }
    delete nuevo;
}

void RedMetro::agregarLinea(Linea* linea) {
    tamano++;
    if(cabeza == nullptr){
        cabeza = linea;
    }
    else{
        bool flag = 0;
        Linea* nueva = cabeza;
        while (!flag)
        {
            if (nueva->getsiguiente()==nullptr){
                nueva->reroute(linea);
                flag = 1;
            }
            else{
                nueva = nueva->getsiguiente();
            }
        }
    }
}

void RedMetro::mostrarLineas() {
    cout << "Cantidad de lineas en la red: " << tamano << endl;
}

Linea* RedMetro::pertenece(string lineademetro)
{
    Linea * nuevo = cabeza;
    while (nuevo != nullptr)
    {
        if (nuevo->getNombre() == lineademetro)
        {
            return nuevo;
        }
        else{
            nuevo = nuevo->getsiguiente();
        }

    }
    return nullptr;
}

int RedMetro::obtenerCantidadEstacionesLinea(string nombreLinea) {

    if (pertenece(nombreLinea) != nullptr) {
        return pertenece(nombreLinea)->obtenerCantidadEstaciones();
    }

    return -1; // Retornar un valor negativo para indicar que la línea no existe
}

bool RedMetro::existeLinea(string nombreLinea) {
    if (pertenece(nombreLinea) != nullptr) {
        return true;
    }

    return false;
}

void RedMetro::eliminarLinea(string nombreLinea) {
    if (pertenece(nombreLinea) != nullptr){
        if (pertenece(nombreLinea)->obtenerCantidadEstaciones()>0){
            cout<< "No se puede eliminar la linea porque tiene estaciones.\n";
            return;
        }
        else {
            Linea * nuevo = cabeza;
            Linea* anterior = nullptr;
            while (nuevo != nullptr)
            {
                if (nuevo->getNombre() == nombreLinea)
                {
                    anterior->reroute(nuevo->getsiguiente());
                    delete nuevo;
                }
                else{
                    anterior=nuevo;
                    nuevo = nuevo->getsiguiente();
                }

            }


        }
    }
    else{
        cout<<"la linea no existe";

    }

}
