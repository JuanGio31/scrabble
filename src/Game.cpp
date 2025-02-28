#include <iostream>
#include <limits>
#include "../include/Game.h"

#include "../include/ManejadorFichas.h"
#include "../include/Tablero.h"

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

//Game::Game() = default;

void Game::play()
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
            iniciar_juego();
            return;
        default:
            std::cout << "Opcion incorrecta! " << std::endl;
            break;
        }
        limpiarPantalla();
        std::cin.clear();
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
        if (numeroJugadores > 1) break;

        std::cout << "!El numero de jugadores debe ser como mínimo de 2¡" << std::endl;
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
    clearView();
    Archivo arc("/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/prueba.csv");
    //lista_palabras = arc.leer_archivo();
    arc.leer_archivo(&lista_palabras);
    ManejadorFichas manejador_fichas(lista_palabras, fichas, jugadores_en_juego_queue);
    manejador_fichas.repartir();
    ordenamiento_burbuja(lista_palabras);

    const int palabras_len = lista_palabras.size();
    int numero = 0;
    Jugador actual = jugadores_en_juego_queue.dequeue();
    //cambiar_turno(actual); //

    //pintar por primera vez el tablero.
    tablero.pintar_tablero();
    while (palabras_len != palabras_jugadas.size() || fichas_en_tablero != fichas.size())
    {
        if (actual.obtener_num_fichas_restantes() == 0)
        {
            jugadores_en_juego_queue.enqueue(actual);
            actual = jugadores_en_juego_queue.dequeue();
            continue;
        }
        std::cout << "\nJugador Actual >>> " << actual.obtener_nombre() << " [ "
            << actual.obtener_puntos() << ". pts ]" << std::endl;

        std::cout << R"(
             _______ OPCIONES ______
            |  1. INGRESAR FICHA.  |
            |  2. PISTA.           |
            | -9. SALIR DEL JUEGO. |
             -----------------------
            )" << std::endl;
        std::cout << "Seleccione una opcion >>> ";
        std::cin >> numero;

        // evitar que se ingrese un tipo de dato diferente de opcion
        //  si el tipo de dato es diferente asignar a opcion un valor de -1
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            numero = -1;
        }

        if (numero == -9) break;
        switch (numero)
        {
        case 1:
            tablero.pintar_tablero();
            actual.mostrar_fichas_disponibles();
            int index;
            std::cout << "Selecciona una opcion (ingresar numero) >>> ";
            std::cin >> index;
            std::cout << "Ingresa una coordenada [FILA],[COLUMNA] Ej: 3,1  >>> ";
            int x, y;
            char coma;
            std::cin >> y >> coma >> x;
            colocarFicha(y, x, index, actual);
            break;
        case 2:
            ver_pista();
            break;
        default:
            std::cout << "Opcion no valida!" << std::endl;
            break;
        }
    }
    //volver a colocar en la cola al jugador.
    jugadores_en_juego_queue.enqueue(actual);
    ver_reportes();
}

void Game::colocarFicha(const int y, const int x, const int index, Jugador& actual)
{
    if (tablero.mov_valido(y - 1, x - 1))
    {
        if (index - 1 > actual.obtener_num_fichas_restantes())
        {
            std::cout << "Fuera del limite!" << std::endl;
            return;
        }
        const auto aux = actual.obtener_ficha(index - 1);
        tablero.colocar(
            y - 1,
            x - 1,
            aux.obtenerLetra(),
            aux.obtenerPuntos());
        actual.eliminar(index - 1); //eliminar ficha del la lista del jugador
        actual.aumentar_movimiento(); //incrementar el numero de movimientos
        analizar(actual); //analizar palabras, sumar pts si se encuentra una palabra.
        fichas_en_tablero++; //incrementar el numero de fichas en el tablero

        //cambiar de jugador
        jugadores_en_juego_queue.enqueue(actual);
        actual = jugadores_en_juego_queue.dequeue();

        clearView();
    }
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
        std::cout
            << (i + 1) << ".- "
            << lista_palabras.search(i)
            << "   ";
    }
    std::cout << std::endl;
}


void Game::clearView()
{
    std::cout << std::endl << std::endl;
}

void Game::analizar(Jugador& actual)
{
    for (int i = 0; i < lista_palabras.size(); ++i)
    {
        auto palabra = lista_palabras.search(i);
        if (palabra_encontrada(this->tablero, palabra) != -1)
        {
            actual.sumar_puntos(palabra_encontrada(this->tablero, palabra));
            palabras_jugadas.push(palabra);
            lista_palabras.deleteAt(i);
        }
    }
}

int Game::palabra_encontrada(Tablero& _tablero, const std::string& palabra)
{
    if (busqueda_horizontal(_tablero, palabra) != -1) return busqueda_horizontal(_tablero, palabra);

    if (busqueda_vertical(_tablero, palabra) != -1) return busqueda_vertical(_tablero, palabra);

    return -1;
}

int Game::busqueda_horizontal(Tablero& _tablero, const std::string& palabra)
{
    int puntos = 0, temp = 1;
    for (int fila = 0; fila < Tablero::FILAS; ++fila)
    {
        int columna = 0, k = 0;
        while (columna < Tablero::COLUMNAS)
        {
            if (k == 0 && columna > Tablero::COLUMNAS - palabra.length())
            {
                break;
            }

            if (_tablero.casillas[fila][columna]->obtenerSimbolo() == ' '
                || _tablero.casillas[fila][columna]->obtenerSimbolo() == '#'
                || !_tablero.ocurrencia(fila, columna, palabra[k]))
            {
                temp = 1;
                puntos = 0;
                k = 0;
            }
            else
            {
                k++;
                temp++;
                puntos += _tablero.casillas[fila][columna]->obtener_puntos();
                if (temp == palabra.length())
                {
                    return puntos;
                }
            }
            columna++;
        }
    }
    return -1;
}

int Game::busqueda_vertical(Tablero& _tablero, const std::string& palabra)
{
    int puntos = 0, temp = 1;
    for (int columna = 0; columna < Tablero::COLUMNAS; ++columna)
    {
        int fila = 0, k = 0;
        while (fila < Tablero::FILAS)
        {
            if (k == 0 && fila > Tablero::FILAS - palabra.length())
            {
                break;
            }

            if (_tablero.casillas[fila][columna]->obtenerSimbolo() == ' '
                || _tablero.casillas[fila][columna]->obtenerSimbolo() == '#'
                || !_tablero.ocurrencia(fila, columna, palabra[k]))
            {
                temp = 1;
                puntos = 0;
                k = 0;
            }
            else
            {
                k++;
                temp++;
                puntos += _tablero.casillas[fila][columna]->obtener_puntos();
                if (temp == palabra.length())
                {
                    return puntos;
                }
            }
            fila++;
        }
    }
    return -1;
}

Game::Game(): reporte(jugadores_en_juego_queue, palabras_jugadas, lista_palabras)
{
}

void Game::ver_reportes()
{
    this->reporte.imprimirReporte();
}
