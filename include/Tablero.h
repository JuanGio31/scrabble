#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"

class Tablero
{
private:
    void iniciar_tablero();

    void bloquear_casilla() const;

    static void pintar_encabezado();

public:
    static constexpr int FILAS = 15;
    static constexpr int COLUMNAS = 15;
    Casilla* casillas[FILAS][COLUMNAS]{};

    Tablero();

    ~Tablero();

    void pintar_tablero() const;

    [[nodiscard]] bool mov_valido(int fila, int columna) const;

    void colocar(int fila, int columna, char sym, int pts) const;

    bool ocurrencia(int fila, int columna, char sym) const;
};

#include "../src/Tablero.tpp"
#endif //TABLERO_H
