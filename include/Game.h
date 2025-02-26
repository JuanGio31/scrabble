#ifndef GAME_H
#define GAME_H

#include <chrono>

#include "Jugador.h"
#include "Tablero.h"
#include "estructuras/Queue.h"
#include "utilidades/Utilidad.h"
#include "../src/estructuras/Queue.cpp"
#include "../src/Archivo.cpp"
#include "estructuras/Stack.h"
#include "../src/estructuras/Stack.cpp"

class Game
{
private:
    Tablero tablero;
    Queue<Jugador> jugadores_en_juego_queue;
    LinkedList<std::string> lista_palabras;
    LinkedList<Ficha> fichas;
    Stack<std::string> palabras_jugadas;
    int fichas_en_tablero = 0;
    std::chrono::steady_clock::time_point inicioTurno;

    void mostrar_menu();
    void ingresar_jugadores();
    void asignar_turnos();
    void iniciar_juego();
    void cambiar_turno(Jugador& actual);
    static void ordenamiento_burbuja(LinkedList<std::string> palabras);
    void ver_pista();
    static void clearView();
    void colocarFicha(int y, int x, int index, Jugador& actual);
    void analizar(Jugador& actual);

    static int palabra_encontrada(Tablero& _tablero, const std::string& palabra);

    static int busqueda_horizontal(Tablero& _tablero, const std::string& palabra);

    static int busqueda_vertical(Tablero& _tablero, const std::string& palabra);

public:
    Game();
    void play();
};
#endif // GAME_H
