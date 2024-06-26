#include <iostream>
#include "estacion.h"
#include "linea.h"
#include "redmetro.h"
#include "Emuladorhora.cpp"

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
    cout << "9. saber tiempo estimado entre estacion\n";
    cout << "10. Salir\n";
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
            int  tiempoAnterior;
            bool esTransferencia;

            cout << "Ingrese el nombre de la linea: ";
            getline(cin, nombreLinea);

            // Verificar si la línea ya existe en la red
            Linea* lineaExistente = red.pertenece(nombreLinea);


            cout << "Ingrese el nombre de la estacion: ";
            getline(cin, nombreEstacion);
            if (lineaExistente){
                cout << "Ingrese el tiempo a la estacion anterior (minutos): ";
                cin >> tiempoAnterior;
            }
            cout << "¿Es estacion de transferencia? (0: No, 1: Si): ";
            cout << "Recuerde que si la estacion es de trasferencia y se encuentra en otra linea deben tener el mismo nombre";
            cin >> esTransferencia;

            cin.ignore(); // Para consumir el salto de línea después de la entrada de enteros

            // Crear una nueva estación
            Estacion* estacion = new Estacion(nombreEstacion, tiempoAnterior, esTransferencia);


            if (!lineaExistente) {
                // Si la línea no existe, crear una nueva línea
                Linea* nuevaLinea = new Linea(nombreLinea);
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

            if (red.pertenece(nombreLinea) != nullptr) {
                red.pertenece(nombreLinea)->eliminarEstacion(nombreEstacion);
                encontrada = true;
                break;
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
            if (red.pertenece(nombreLinea) != nullptr) {
                Estacion* estacion = red.pertenece(nombreLinea)->buscarEstacion(nombreEstacion);
                if (estacion != nullptr) {
                    cout << "La estacion pertenece a la linea " << nombreLinea << endl;
                    pertenece = true;
                }
                break; // Salir del bucle al encontrar la línea
            }
            if (!pertenece) {
                cout << "La estacion no pertenece a la linea " << nombreLinea << endl;
            }
            break;
        }
        case 6: {
            string nombreLinea;

            cout << "Ingrese el nombre de la linea: ";
            getline(cin, nombreLinea);

            if (!red.existeLinea(nombreLinea)) {
                Linea* linea = new Linea(nombreLinea);
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
        case 8: {
            int totalEstaciones = 0;
            Linea* lineaActual = red.obtenerPrimeraLinea(); // Obtener la primera línea en la red de metro

            while (lineaActual != nullptr) {
                int cantidadEstaciones = red.obtenerCantidadEstacionesLinea(lineaActual->getNombre());
                if (cantidadEstaciones >= 0) {
                    totalEstaciones += cantidadEstaciones; // Sumar la cantidad de estaciones en la línea actual
                } else {
                    cout << "Error: La línea " << lineaActual->getNombre() << " no existe en la red.\n";
                }
                lineaActual = red.obtenerSiguienteLinea(lineaActual); // Avanzar a la siguiente línea
            }

            cout << "La red de metro tiene un total de " << totalEstaciones << " estaciones.\n";
            break;
        }

        case 9: {
            // Realizar la simulación
            calcularTiempoLlegada(red);
            break;
        }

        case 10:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }
        } while (opcion != 10);

        return 0;
    }
