#include "../include/Jugador.h"

Jugador::Jugador(const std::string& _nombre)
{
    this->nombre = _nombre;
    this->movimientos = 0;
}

void Jugador::aumentarMovimiento()
{
    this->movimientos++;
}

std::string Jugador::obtenerNombre()
{
    return std::string(this->nombre);
}

int Jugador::obtenerMovimientos()
{
    return this->movimientos;
}
