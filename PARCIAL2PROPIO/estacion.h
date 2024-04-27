#ifndef ESTACION_H
#define ESTACION_H

#include <string>
#include <fstream>

using namespace std;

class Estacion {
public:
    Estacion(const string& nombre, int tiempoSiguiente, int tiempoAnterior);

    // Getters
    string getNombre() const;
    int getTiempoSiguiente() const;
    int getTiempoAnterior() const;

    // Setters
    void setNombre(const string& nuevoNombre);
    void setTiempoSiguiente(int nuevoTiempo);
    void setTiempoAnterior(int nuevoTiempo);

    // Método para guardar la estación en un archivo
    void guardar(ofstream& archivo) const;

    // Método para cargar una estación desde un archivo
    static Estacion cargar(ifstream& archivo);

    // Método para cargar una estación desde un archivo especificado por el usuario
    static Estacion cargarDesdeArchivo();

private:
    string nombre;
    int tiempoSiguiente;
    int tiempoAnterior;
};

#endif // ESTACION_H
