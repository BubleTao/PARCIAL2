#include <iostream>
#include <string>
#include <chrono>
#include "redmetro.h"

using namespace std;
using namespace std::chrono;

void calcularTiempoLlegada(RedMetro& red) {
    auto tiempoActual = system_clock::to_time_t(system_clock::now());
    tm* horaActual = localtime(&tiempoActual);
    cout << "Hora de salida: " << horaActual->tm_hour << ":" << horaActual->tm_min << endl;
    string nombreLinea, estacionOrigen, estacionDestino;
    cout << "Ingrese el nombre de la linea: ";
    getline(cin, nombreLinea);
    cout << "Ingrese la estacion de origen: ";
    getline(cin, estacionOrigen);
    cout << "Ingrese la estacion de destino: ";
    getline(cin, estacionDestino);
    Linea* linea = red.pertenece(nombreLinea);
    if (linea == nullptr) {
        cout << "La linea especificada no existe en la red.\n";
        return;
    }
    Estacion* estacionInicio = linea->buscarEstacion(estacionOrigen);
    Estacion* estacionFin = linea->buscarEstacion(estacionDestino);
    if (estacionInicio == nullptr || estacionFin == nullptr) {
        cout << "Una o ambas estaciones especificadas no existen en la linea.\n";
        return;
    }
    int minutosViaje = estacionFin->getTiempoAnterior();
    int horasLlegada = horaActual->tm_hour;
    int minutosLlegada = horaActual->tm_min + minutosViaje;
    if (minutosLlegada >= 60) {
        horasLlegada += minutosLlegada / 60;
        minutosLlegada %= 60;
    }
    cout << "Hora de llegada estimada: " << horasLlegada << ":" << minutosLlegada << endl;
}
