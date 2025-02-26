#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Ficha.h"
#include "estructuras/LinkedList.h"
#include "../src/estructuras/LinkedList.cpp"

class Jugador
{
private:
    int puntos;
    std::string nombre;
    LinkedList<Ficha> lista_fichas;
    int movimientos;
    bool existe(int index);

public:
    explicit Jugador();
    explicit Jugador(const std::string& _nombre);
    [[nodiscard]] std::string obtener_nombre() const;
    [[nodiscard]] int obtener_movimientos() const;
    [[nodiscard]] int obtener_puntos() const;
    void sumar_puntos(int pts);
    void restar_puntos(int pts);
    void aumentar_movimiento();
    void set_nombre(std::string _nombre);
    Ficha obtener_ficha(int index);
    void mostrar_fichas_disponibles();
    void eliminar(int index);

    void ordenar();
    void insertar(Ficha ficha);
    [[nodiscard]] int obtener_num_fichas_restantes() const;
};
#endif // JUGADOR_H
