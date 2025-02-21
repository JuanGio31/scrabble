#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

#include "ManejadorFichas.h"

class Jugador
{
private:
    std::string nombre;
    //ManejadorFichas fichas;
    int movimientos;

public:
    explicit Jugador(const std::string& _nombre);
    [[nodiscard]] std::string obtenerNombre() const;
    [[nodiscard]] int obtenerMovimientos() const;
    void aumentarMovimiento();
};
#endif //JUGADOR_H
