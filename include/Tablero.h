#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"
#include "utilidades/Utilidad.h"
class Tablero
{
private:
    static constexpr int FILAS = 15;
    static constexpr int COLUMNAS = 15;
    Casilla* casillas[FILAS][COLUMNAS];
    void iniciar_tablero();
    void bloquear_casilla() const;
    static void pintar_encabezado();

public:
    Tablero();
    ~Tablero();
    void pintar_tablero() const;
};
#endif //TABLERO_H
