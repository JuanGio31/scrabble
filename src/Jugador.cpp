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

[[nodiscard]] std::string Jugador::obtenerNombre() const
{
    return this->nombre;
}

[[nodiscard]] int Jugador::obtenerMovimientos() const
{
    return this->movimientos;
}
