#include "../include/Tablero.h"

#include <iostream>


Tablero::Tablero()
{
    srand(time(0));
    iniciar_tablero();
}

void Tablero::iniciar_tablero()
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            //32 representa un espacio en blanco
            //casillas[i][j] = new Casilla(32, i, j);
            casillas[i][j] = new Casilla(32);
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
        if (casillas[fila][col]->obtenerSimbolo() == 32) //32 representa un espacio
        {
            casillas[fila][col]->asignar_simbolo('#');
            casillas[fila][col]->bloquear();
            //casillas[fila][col] = new Casilla(); //new Casilla(fila, col);
            contador++;
        }
    }
}

void Tablero::pintarEncabezado()
{
    for (int i = 0; i < FILAS; ++i)
    {
        if (i == 0)
        {
            std::cout << "\t " << i + 1;
        }
        else if (i < 9)
        {
            std::cout << "   " << i + 1;
        }
        else
        {
            std::cout << "  " << i + 1;
        }
    }
    std::cout << std::endl;
}

void Tablero::pintar_tablero()
{
    pintarEncabezado();
    for (int i = 0; i < FILAS; i++)
    {
        std::cout << i + 1 << "\t";
        for (int j = 0; j < COLUMNAS; j++)
        {
            std::cout << "[" << casillas[i][j]->obtenerSimbolo() << "]" << " ";
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
            casillas[i][j] = nullptr;
        }
    }
}
