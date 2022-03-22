#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../include/arbolBB.hpp"
#include "../include/dni.hpp"
#include "../include/nodoBB.hpp"
int Dni::ncomparaciones_ = 0;

int main(void) {
    srand(time(NULL));
    int opt = 0, size = 0, pruebas = 0, opcion = 0;

    std::cout << "Introduzca cual de los modos de ejecucion quiere ejecutar: " << std::endl;
    std::cout << "1.Modo Demostracion" << std::endl;
    std::cout << "2.Modo Estadistica" << std::endl;
    std::cout << "Modo: ";
    std::cin >> opt;

    ArbolBB<Dni> tree;
    tree.write();
    switch (opt) {
        case 1: {
            while (opcion != 1) {
                std::cout << "--------MODO DEMOSTRACION--------" << std::endl;
                std::cout << "Introduzca un numero para elegir una de las acciones: " << std::endl;
                std::cout << "[1] Salir" << std::endl;
                std::cout << "[2] Insertar clave" << std::endl;
                std::cout << "[3] Eliminar clave" << std::endl;
                std::cin >> opcion;

                switch (opcion) {
                    case 1: {
                        break;
                    }
                    case 2: {
                        unsigned long dato;
                        std::cout << "Introduzca la clave a insertar: " << std::endl;
                        std::cin >> dato;
                        Dni aux(dato);
                        // tree.write();
                        tree.Insertar(aux);
                        tree.write();
                        break;
                    }
                    case 3: {
                        unsigned long dato;
                        std::cout << "Introduzca la clave a eliminar: " << std::endl;
                        std::cin >> dato;
                        Dni aux(dato);
                        // tree.write();
                        tree.Eliminar(aux);
                        tree.write();
                        break;
                    }
                }
            }
            break;
        }
        case 2: {
            std::cout << "--------MODO ESTADISTICA--------" << std::endl;
            std::cout << "Introduzca el tamaño del arbol: " << std::endl;
            std::cout << "Tamaño: ";
            std::cin >> size;
            // ArbolBB<Dni> tree;
            vector<Dni> vector(size * 2);

            for (int j = 0; j < size; j++) {
                tree.Insertar(vector[j]);
            }

            std::cout << "Introduzca el numero de pruebas a realizar: " << std::endl;
            std::cin >> pruebas;
            int j = 0, max_busqueda = 0, min_busqueda = 9999999, min_insertar = 9999999, max_insertar = 0;
            int acumulado1 = 0;
            int acumulado2 = 0;

            while (j < pruebas) {
                Dni::ncomparaciones_ = 0;
                int i = rand() % (size * 2);
                tree.buscar(vector[i]);
                if (vector[i].get_comparaciones() < min_insertar) min_insertar = vector[i].get_comparaciones();
                if (vector[i].get_comparaciones() > max_insertar) max_insertar = vector[i].get_comparaciones();
                acumulado1 += vector[i].get_comparaciones();
                int k = (size * 2) + rand() % ((size * 2) - 1);
                tree.buscar(vector[k]);
                if (vector[k].get_comparaciones() < min_busqueda) min_busqueda = vector[k].get_comparaciones();
                if (vector[k].get_comparaciones() > max_busqueda) max_busqueda = vector[k].get_comparaciones();
                acumulado2 += vector[i].get_comparaciones();
                j++;
            }
            std::cout << "\t\tNumero de comparaciones" << std::endl;
            std::cout << std::endl;
            std::cout << std::setw(14) << "\tN" << std::setw(12) << "NPruebas" << std::setw(12) << "Minimo" << std::setw(10) << "Medio" << std::setw(10) << "Maximo" << std::endl;
            std::cout << "Busqueda: " << std::setw(7) << size << std::setw(12) << pruebas << std::setw(12) << min_busqueda << std::setw(10) << acumulado1 / pruebas << std::setw(10) << max_busqueda << std::endl;
            std::cout << "Inserción " << std::setw(7) << size << std::setw(12) << pruebas << std::setw(12) << min_insertar << std::setw(10) << acumulado2 / pruebas << std::setw(10) << max_insertar << std::endl;

            break;
        }
    }
    return 0;
}
