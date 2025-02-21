#ifndef GAME_H
#define GAME_H

#include "Jugador.h"
#include "Tablero.h"
#include "estructuras/Queue.h"
//#include "../src/estructuras/Queue.cpp"

class Game
{
private:
    Tablero tablero;
    Queue<Jugador> jugadoresEnJuego;
    void mostrar_menu();
    void ingresarJugadores();

public:
    Game();
};
#endif //GAME_H
