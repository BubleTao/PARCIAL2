#include "Estacion.h"
#include <iostream>
#include <fstream>
#include <sstream>

Estacion::Estacion(const string& nombre, int tiempoSiguiente, int tiempoAnterior)
    : nombre(nombre), tiempoSiguiente(tiempoSiguiente), tiempoAnterior(tiempoAnterior) {}

string Estacion::getNombre() const {
    return nombre;
}

int Estacion::getTiempoSiguiente() const {
    return tiempoSiguiente;
}

int Estacion::getTiempoAnterior() const {
    return tiempoAnterior;
}

void Estacion::setNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Estacion::setTiempoSiguiente(int nuevoTiempo) {
    tiempoSiguiente = nuevoTiempo;
}

void Estacion::setTiempoAnterior(int nuevoTiempo) {
    tiempoAnterior = nuevoTiempo;
}

void Estacion::guardar(ofstream& archivo) const {
    archivo << "Estacion:" << nombre << "," << tiempoSiguiente << "," << tiempoAnterior << "\n";
}

Estacion Estacion::cargar(ifstream& archivo) {
    string linea;
    getline(archivo, linea);

    // Verificar si la línea comienza con "Estacion:"
    if (linea.find("Estacion:") != string::npos) {
        // Procesar la línea
        stringstream ss(linea);
        string etiqueta, nombre;
        int tiempoSiguiente, tiempoAnterior;

        // Leer la etiqueta "Estacion:"
        ss >> etiqueta;
        // Eliminar la parte "Estacion:"
        nombre = linea.substr(9); // 9 es la longitud de "Estacion:"
        // Leer los tiempos
        ss >> tiempoSiguiente;
        ss >> tiempoAnterior;

        return Estacion(nombre, tiempoSiguiente, tiempoAnterior);
    } else {
        // Ignorar líneas que no comienzan con "Estacion:"
        return Estacion("", 0, 0);
    }
}

Estacion Estacion::cargarDesdeArchivo() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo para cargar la informacion de las estaciones: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    return cargar(archivo);
}
