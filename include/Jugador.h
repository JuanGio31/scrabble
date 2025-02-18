#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

#include "ManejadorFichas.h"

class Jugador
{
private:
    std::pmr::string nombre;
    ManejadorFichas fichas;
    int movimientos;

public:
    Jugador(const std::string& _nombre);
    std::string obtenerNombre();
    int obtenerMovimientos();
    void aumentarMovimiento();
};
#endif //JUGADOR_H
