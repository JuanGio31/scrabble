#ifndef GAME_H
#define GAME_H

#include "Jugador.h"
#include "Tablero.h"
#include "estructuras/Queue.h"
#include "utilidades/Utilidad.h"
// #include "../src/estructuras/Queue.cpp"

class Game
{
private:
    Tablero tablero;
    Queue<Jugador> jugadores_en_juego_queue;
    LinkedList<std::string> lista_palabras;

    void mostrar_menu();
    void ingresar_jugadores();
    void asignar_turnos();
    void iniciar_juego();
    void cambiar_turno(Jugador actual);
    static void ordenamiento_burbuja(LinkedList<std::string> palabras);
    void ver_pista();
public:
    Game();
};
#endif // GAME_H
