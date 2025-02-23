#include <utility>

#include "../include/Jugador.h"

Jugador::Jugador()
{
    this->nombre = "";
    this->movimientos = 0;
}

Jugador::Jugador(std::string& _nombre)
{
    this->nombre = _nombre;
    this->movimientos = 0;
}

void Jugador::aumentar_movimiento()
{
    this->movimientos++;
}

[[nodiscard]] std::string Jugador::obtener_nombre() const
{
    return this->nombre;
}

[[nodiscard]] int Jugador::obtener_movimientos() const
{
    return this->movimientos;
}

void Jugador::set_nombre(std::string _nombre)
{
    this->nombre = std::move(_nombre);
}
