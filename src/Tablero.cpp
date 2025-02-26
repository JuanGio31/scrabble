#include "../include/Tablero.h"

#include <iostream>

Tablero::Tablero()
{
    iniciar_tablero();
}

void Tablero::iniciar_tablero()
{
    for (auto& casilla : casillas)
    {
        for (auto& j : casilla)
        {
            //32 representa un espacio en blanco
            j = new Casilla(32, 0);
        }
    }
    bloquear_casilla();
}

void Tablero::bloquear_casilla() const
{
    static constexpr int INUTILIZABLES = 10;
    int contador = 0;
    while (contador < INUTILIZABLES)
    {
        int fila = Utilidad::getRandomInt(1, FILAS) - 1; //rand() % FILAS;
        int col = Utilidad::getRandomInt(1, COLUMNAS) - 1;; //rand() % COLUMNAS;
        if (casillas[fila][col]->obtenerSimbolo() == 32) //32 representa un espacio
        {
            casillas[fila][col]->setFicha('#', 0);
            casillas[fila][col]->bloquear();
            contador++;
        }
    }
}

void Tablero::pintar_encabezado()
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

void Tablero::pintar_tablero() const
{
    pintar_encabezado();
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

bool Tablero::mov_valido(int fila, int columna) const
{
    if (casillas[fila][columna]->obtenerSimbolo() == ' ')
    {
        return true;
    }

    return fila >= 0 && fila < 15 && columna >= 0 && columna < 15;
}

void Tablero::colocar(int fila, int columna, char sym, int pts) const
{
    casillas[fila][columna]->setFicha(sym, pts);
}

bool Tablero::ocurrencia(int fila, int columna, char sym)
{
    return casillas[fila][columna]->obtenerSimbolo() == sym;
}


Tablero::~Tablero()
{
    for (auto& casilla : casillas)
    {
        for (auto& j : casilla)
        {
            delete j;
            j = nullptr;
        }
    }
}
