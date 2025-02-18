#ifndef TABLERO_H
#define TABLERO_H
#include "Casilla.h"

class Tablero
{
private:
    static const int FILAS = 15;
    static const int COLUMNAS = 15;
    Casilla* casillas[FILAS][COLUMNAS];
    void iniciar_tablero();
    void bloquear_casilla();

public:
    Tablero();
    ~Tablero();
    void pintar_tablero();
};
#endif //TABLERO_H
