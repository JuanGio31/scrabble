#include <iostream>
#include <limits>
#include "../include/Game.h"

#include "../include/ManejadorFichas.h"
#include "../include/Tablero.h"
//#include "estructuras/Queue.cpp"
//#include "estructuras/LinkedList.cpp"

#ifdef _WIN32
#include <windows.h>
#include "Game.h"
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

//funciona
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
            _________ MENU ________
            | 1. INICIAR JUEGO.   |
            | 2. ESTADISTICAS.    |
            | 0. SALIR DEL JUEGO. |
            -----------------------
            )" << std::endl;
        std::cout << "Seleccione una opcion >>> ";
        std::cin >> opcion;

        // evitar que se ingrese un tipo de dato diferente de opcion
        //  si el tipo de dato es diferente asignar a opcion un valor de -1
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        }

        switch (opcion)
        {
        case 0:
            std::cout << "Saliendo...\n" << std::endl;
            break;
        case 1:
            //            iniciar_juego();
            tablero.pintar_tablero();
            break;
        case 2:
            //std::cout << "Reportes." << std::endl;
            std::cout << "Prueba cambio de jugadores\n\n";
            iniciar_juego();
            break;
        default:
            std::cout << "Opcion incorrecta! " << std::endl;
            break;
        }
        limpiarPantalla();
        std::cin.clear();
    }

    const int size = jugadores_en_juego_queue.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << jugadores_en_juego_queue.dequeue().obtener_nombre() << " ";
    }
}

//funciona
void Game::ingresar_jugadores()
{
    int numeroJugadores = -1;
    while (true)
    {
        std::cout << "Ingrese la cantidad de jugadores >>> ";
        std::cin >> numeroJugadores;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            numeroJugadores = -1;
        }

        if (numeroJugadores < 2)
        {
            std::cout << "!El numero de jugadores debe ser como mínimo de 2¡" << std::endl;
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
        std::cout << "Ingrese el nombre de su jugador >>> ";
        std::cin >> nombre;
        jugadores_en_juego_queue.enqueue(Jugador(nombre));
        aux++;
    }
    asignar_turnos();
}

//funciona
void Game::asignar_turnos()
{
    const int n = jugadores_en_juego_queue.size();
    auto* arr = new Jugador[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = jugadores_en_juego_queue.dequeue();
    }

    //Implementar el algoritmo de Fisher-Yates para mezclar el array
    for (int i = n - 1; i > 0; i--)
    {
        int j = Utilidad::getRandomInt(0, i);
        //intercambiar arr[i] y arr[j]
        auto temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //reinsercion de los elementos mezclados en la cola.
    for (int i = 0; i < n; i++)
    {
        jugadores_en_juego_queue.enqueue(arr[i]);
    }

    //liberar la memoria del arreglo
    delete[] arr;
}

void Game::iniciar_juego()
{
    ingresar_jugadores();
    Archivo arc("/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/prueba.csv");
    //lista_palabras = arc.leer_archivo();
    arc.leer_archivo(&lista_palabras);
    ManejadorFichas manejador_fichas;
    manejador_fichas.generarListaFichas(lista_palabras);
    manejador_fichas.repartirFichas(jugadores_en_juego_queue);


    int numero = 0;
    while (numero != -1)
    {
        std::cout << "Ingresa un numero >>> ";
        std::cin >> numero;
        cambiar_turno();
    }
}

//funciona?
void Game::cambiar_turno()
{
    Jugador actual = jugadores_en_juego_queue.dequeue();
    std::cout << "Jugador actual >>> " << actual.obtener_nombre() << std::endl;
    actual.mostrar_fichas_disponibles();
    jugadores_en_juego_queue.enqueue(actual);
}

//sin probar
void Game::ordenamiento_burbuja(LinkedList<std::string> palabras)
{
    const int n = palabras.size();
    //crear una lista temporal para almacenar los elementos de la LinkedList.
    auto* lista = new std::string[n];
    for (int i = 0; i < n; ++i)
    {
        lista[i] = palabras.search(0);
        palabras.deleteAtHead();
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (lista[j] > lista[j + 1])
            {
                //intercambiar elementos
                std::string aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    //insertar los elementos ordenados a la lista original
    for (int i = 0; i < n; ++i)
    {
        palabras.insertAtEnd(lista[i]);
    }
    delete [] lista;
}

void Game::ver_pista()
{
    for (int i = 0; i < this->lista_palabras.size(); ++i)
    {
        std::string whitespace = (i % 3 == 0) ? "\n" : " "; //operador ternario
        std::cout
            << std::endl
            << (i + 1) << ".- "
            << lista_palabras.search(i)
            << whitespace;
    }
}

// std::cout << "letra   puntos";
// std::cout << "  ↓       ↓";
// std::cout << "  A     [10].";
