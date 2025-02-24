#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

#include "Ficha.h"
#include "estructuras/LinkedList.h"
#include "../src/estructuras/LinkedList.cpp"

class Jugador
{
private:
    std::string nombre;
    // ManejadorFichas fichas;
    LinkedList<Ficha> lista_fichas;
    int movimientos;
    bool existe(int index);

public:
    explicit Jugador();
    explicit Jugador(std::string& _nombre);
    [[nodiscard]] std::string obtener_nombre() const;
    [[nodiscard]] int obtener_movimientos() const;
    void aumentar_movimiento();
    void set_nombre(std::string _nombre);
    Ficha obtener_ficha(int index);
    void mostrar_fichas_disponibles();
    void eliminar(int index);
    LinkedList<Ficha> obetener_fichas_list();
    void insertar(Ficha ficha);
};
#endif // JUGADOR_H
