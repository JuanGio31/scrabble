#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

#include "ManejadorFichas.h"

class Jugador
{
private:
    std::string nombre;
    // ManejadorFichas fichas;

    int movimientos;

public:
    explicit Jugador();
    explicit Jugador(std::string& _nombre);
    [[nodiscard]] std::string obtener_nombre() const;
    [[nodiscard]] int obtener_movimientos() const;
    void aumentar_movimiento();
    void set_nombre(std::string _nombre);
};
#endif // JUGADOR_H
