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

            cin.ignore(); // Para consumir el salto de línea después de la entrada de enteros

            // Crear una nueva estación
            Estacion* estacion = new Estacion(nombreEstacion, tiempoSiguiente, tiempoAnterior, esTransferencia);

            // Verificar si la línea ya existe en la red
            Linea* lineaExistente = nullptr;
            for (Linea* linea : red.getLineas()) {
                if (linea->getNombre() == nombreLinea) {
                    lineaExistente = linea;
                    break;
                }
            }

            if (!lineaExistente) {
                // Si la línea no existe, crear una nueva línea
                Linea* nuevaLinea = new Linea(nombreLinea, "tren");
                nuevaLinea->agregarEstacion(estacion); // Agregar la estación a la nueva línea
                red.agregarLinea(nuevaLinea); // Agregar la nueva línea a la red
                cout << "Estacion agregada correctamente a una nueva linea.\n";
            } else {
                // Si la línea ya existe, agregar la estación a esa línea
                lineaExistente->agregarEstacion(estacion);
                cout << "Estacion agregada correctamente a la linea existente.\n";
            }
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
            red.mostrarLineas();
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
        case 5: {
            string nombreLinea, nombreEstacion;

            cout << "Ingrese el nombre de la linea: ";
            getline(cin, nombreLinea);
            cout << "Ingrese el nombre de la estacion: ";
            getline(cin, nombreEstacion);

            bool pertenece = false;
            for (Linea* linea : red.getLineas()) {
                if (linea->getNombre() == nombreLinea) {
                    Estacion* estacion = linea->buscarEstacion(nombreEstacion);
                    if (estacion != nullptr) {
                        cout << "La estacion pertenece a la linea " << nombreLinea << endl;
                        pertenece = true;
                    }
                    break; // Salir del bucle al encontrar la línea
                }
            }
            if (!pertenece) {
                cout << "La estacion no pertenece a la linea " << nombreLinea << endl;
            }
            break;
        }
        case 6: {
            string nombreLinea, tipoTransporte;

            cout << "Ingrese el nombre de la linea: ";
            getline(cin, nombreLinea);
            cout << "Ingrese el tipo de transporte: ";
            getline(cin, tipoTransporte);

            if (!red.existeLinea(nombreLinea)) {
                Linea* linea = new Linea(nombreLinea, tipoTransporte);
                red.agregarLinea(linea);
                cout << "Linea agregada a la red Metro correctamente.\n";
            } else {
                cout << "La linea ya existe en la red Metro.\n";
            }
            break;
        }
        case 7: {
            string nombreLinea;

            cout << "Ingrese el nombre de la linea a eliminar: ";
            getline(cin, nombreLinea);

            red.eliminarLinea(nombreLinea);

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
