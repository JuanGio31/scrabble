#ifndef GAME_H
#define GAME_H

#include <chrono>

#include "Reporte.h"
#include "Tablero.h"
#include "estructuras/LinkedList.h"
#include "estructuras/Queue.h"
#include "estructuras/Stack.h"

class Game
{
private:
    int fichas_en_tablero = 0;
    Tablero tablero;
    Queue<Jugador> jugadores_en_juego_queue;
    LinkedList<std::string> lista_palabras;
    LinkedList<Ficha> fichas;
    Stack<std::string> palabras_jugadas;
    Reporte reporte;
    std::chrono::steady_clock::time_point inicioTurno;

    void ver_reportes();
    void mostrar_menu();
    void ingresar_jugadores();
    void asignar_turnos();
    void iniciar_juego();
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

#include "../src/Game.tpp"
#endif // GAME_H
