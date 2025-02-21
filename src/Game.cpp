#include <iostream>
#include <limits>
#include "../include/Game.h"
#include "../include/Tablero.h"
#include "estructuras/Queue.cpp"

#ifdef _WIN32
#include <windows.h>
#endif

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

Game::Game()
{
    mostrar_menu();
}

void Game::mostrar_menu()
{
    std::cout << R"(
                        _     _     _
     ___  ___ _ __ __ _| |__ | |__ | | ___
    / __|/ __| '__/ _` | '_ \| '_ \| |/ _ \
    \__ \ (__| | | (_| | |_) | |_) | |  __/
    |___/\___|_|  \__,_|_.__/|_.__/|_|\___|
    )" << std::endl;

    int opcion = -1;
    while (opcion != 0)
    {
        std::cout << R"(
            _________ MENU _______
            | 1. INICIAR JUEGO   |
            | 2. ESTADISTICAS    |
            | 0. SALIR DEL JUEGO |
            ----------------------
            )" << std::endl;
        std::cout << "Seleccione una opcion > ";
        std::cin >> opcion;

        //evitar que se ingrese un tipo de dato diferente de opcion
        // si el tipo de dato es diferente asignar a opcion un valor de -1
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        }

        switch (opcion)
        {
        case 0:
            std::cout << "Saliendo" << std::endl;
            break;
        case 1:
            std::cout << "A seleccionado la opcion 1" << std::endl;
            ingresarJugadores();
            tablero.pintar_tablero();
            break;
        case 2:
            std::cout << "A seleccionado la opcion 2" << std::endl;
            break;
        default:
            std::cout << "opcion incorrecta" << std::endl;
            break;
        }
        limpiarPantalla();
        std::cin.clear();
    }

    const int size = jugadoresEnJuego.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << jugadoresEnJuego.dequeue().obtenerNombre() << " ";
    }
}

void Game::ingresarJugadores()
{
    //std::cout << "Ingresar jugadores\n";
    int numeroJugadores = -1;
    while (true)
    {
        std::cout << "Ingrese la cantidad de jugadores > ";
        std::cin >> numeroJugadores;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            numeroJugadores = -1;
        }

        if (numeroJugadores < 2)
        {
            std::cout << "\n!El numero de jugadores debe ser como mínimo de 2¡";
        }
        else
        {
            break;
        }
    }

    int aux = 0;
    while (aux < numeroJugadores)
    {
        std::string nombre = " ";
        std::cout << "\nIngrese el nombre de su jugador > ";
        std::cin >> nombre;
        jugadoresEnJuego.enqueue(Jugador(nombre));
        aux++;
    }
}

/*  Simulacionde sistema de turnos con una Cola
    for (int i = 0; i < 10; ++i) {
        Jugador actual = turnos.dequeue();
        std::cout << "Turno de: " << actual.nombre << std::endl;
        // Procesa el turno...
        // Vuelve a encolar al jugador al finalizar su turno
        turnos.enqueue(actual);
    }
 */
