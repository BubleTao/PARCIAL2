#include <iostream>
#include "estacion.h"
#include "linea.h"
#include "redmetro.h"

using namespace std;

void mostrarMenu() {
    cout << "\n*** Menu ***\n";
    cout << "1. Agregar una estacion a una linea\n";
    cout << "2. Eliminar una estacion de una linea\n";
    cout << "3. Saber cuantas lineas tiene una red Metro\n";
    cout << "4. Saber cuantas estaciones tiene una linea dada\n";
    cout << "5. Saber si una estacion dada pertenece a una linea especifica\n";
    cout << "6. Agregar una linea a la red Metro\n";
    cout << "7. Eliminar una linea de la red Metro\n";
    cout << "8. Saber cuantas estaciones tiene una red Metro\n";
    cout << "9. Salir\n";
    cout << "Ingrese su opcion: ";
}

int main() {
    RedMetro red;
    string nombreLinea;
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
        case 1: {
            string nombreLinea, nombreEstacion;
            int tiempoSiguiente, tiempoAnterior;
            bool esTransferencia;

            cout << "Ingrese el nombre de la linea: ";
            getline(cin, nombreLinea);
            cout << "Ingrese el nombre de la estacion: ";
            getline(cin, nombreEstacion);
            cout << "Ingrese el tiempo a la estacion siguiente (segundos): ";
            cin >> tiempoSiguiente;
            cout << "Ingrese el tiempo a la estacion anterior (segundos): ";
            cin >> tiempoAnterior;
            cout << "¿Es estacion de transferencia? (0: No, 1: Si): ";
            cin >> esTransferencia;

            Linea* linea = new Linea(nombreLinea, "tren");
            Estacion* estacion = new Estacion(nombreEstacion, tiempoSiguiente, tiempoAnterior, esTransferencia);
            linea->agregarEstacion(estacion);
            red.agregarLinea(linea);

            cout << "Estacion agregada correctamente.\n";
            break;
        }
        case 2: {
            string nombreLinea, nombreEstacion;
            cout << "Ingrese el nombre de la linea: ";
            getline(cin, nombreLinea);
            cout << "Ingrese el nombre de la estacion a eliminar: ";
            getline(cin, nombreEstacion);

            // Buscar la linea en la red y eliminar la estacion
            bool encontrada = false;
            for (Linea* linea : red.getLineas()) {
                if (linea->getNombre() == nombreLinea) {
                    linea->eliminarEstacion(nombreEstacion);
                    encontrada = true;
                    break;
                }
            }
            if (!encontrada) {
                cout << "La linea especificada no existe en la red.\n";
            }
            break;
        }
        case 3:
            // Código para mostrar la cantidad de líneas en la red
            break;
        case 4:
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            if (red.existeLinea(nombreLinea)) {
                cout << "Cantidad de estaciones en la linea " << nombreLinea << ": "
                     << red.obtenerCantidadEstacionesLinea(nombreLinea) << endl;
            } else {
                cout << "La linea no existe en la red.\n";
            }
            break;
        case 5:
            // Código para verificar si una estación pertenece a una línea
            break;
        case 6: {
            // Código para agregar una línea a la red Metro
            break;
        }
        case 7: {
            // Código para eliminar una línea de la red Metro
            break;
        }
        case 8:
            // Código para mostrar la cantidad de estaciones en la red Metro
            break;
        case 9:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 9);

    return 0;
}
