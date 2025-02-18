#include "../include/Tablero.h"

#include <iostream>


Tablero::Tablero()
{
    srand(time(0));
    iniciar_tablero();
}

void Tablero::iniciar_tablero()
{
    for (int i = 0; i < FILAS; ++i)
    {
        for (int j = 0; j < COLUMNAS; ++j)
        {
            casillas[i][j] = new Casilla('.', i, j);
        }
    }

    bloquear_casilla();
}

void Tablero::bloquear_casilla()
{
    static const int INUTILIZABLES = 10;
    int contador = 0;
    while (contador < INUTILIZABLES)
    {
        int fila = rand() % FILAS;
        int col = rand() % COLUMNAS;
        if (casillas[fila][col]->obtenerSimbolo() == '.')
        {
            casillas[fila][col] = new Casilla(fila, col);
            contador++;
        }
    }
}

void Tablero::pintar_tablero()
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            std::cout << casillas[i][j]->obtenerSimbolo() << " ";
        }
        std::cout << std::endl;
    }
}

Tablero::~Tablero()
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            delete casillas[i][j];
        }
    }
}
