#include <iostream>
#include <fstream>
#include "Estacion.h"

using namespace std;

int main() {
    // Cargar información de las estaciones desde un archivo
    cout << "Ingrese el nombre del archivo para cargar la informacion de las estaciones: ";
    string nombreArchivo;
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    // Mostrar estaciones
    cout << "Estaciones y sus valores:" << endl;
    while (!archivo.eof()) {
        Estacion estacion = Estacion::cargar(archivo);
        if (estacion.getNombre() != "") {
            cout << "Nombre: " << estacion.getNombre() << endl;
            cout << "Tiempo Siguiente: " << estacion.getTiempoSiguiente() << endl;
            cout << "Tiempo Anterior: " << estacion.getTiempoAnterior() << endl;
            cout << endl;
        }
    }

    archivo.close();

    return 0;
}
