#include "../include/Jugador.h"

#include <iostream>
#include <stdexcept>

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

bool Jugador::existe(int index)
{
    try
    {
        lista_fichas.search(index);
        return true;
    }
    catch ([[maybe_unused]] std::exception& e)
    {
        return false;
    }
}

void Jugador::eliminar(int index)
{
    lista_fichas.deleteAt(index);
}

LinkedList<Ficha> Jugador::obetener_fichas_list()
{
    return this->lista_fichas;
}


Ficha Jugador::obtener_ficha(int index)
{
    if (existe(index))
    {
        return lista_fichas.search(index);
    }
    //Manejar exception
    throw std::out_of_range("Indice fuera de rango");
}

void Jugador::mostrar_fichas_disponibles()
{
    std::cout << std::endl;;
    if (!lista_fichas.empty())
    {
        std::cout << "\nletra   puntos" << std::endl;
        std::cout << "  ↓       ↓" << std::endl;
        std::cout << " {A}     [10]." << std::endl << std::endl;

        const int size = this->lista_fichas.size(); //obtener tamanio de la lista

        int j = 0;
        for (int i = 0; i < size; ++i)
        {
            std::string whitespace = "\t\t\t";
            if (j > 4)
            {
                whitespace = "\n";
                j = -1;
            }
            std::cout << (i + 1) << ".-  {" << lista_fichas.search(i).obtenerLetra() << "} [" << lista_fichas.
                search(i).
                obtenerPuntos() << "]" << whitespace;
            j++;
        }
    }
    else
    {
        std::cout << "No hay fichas disponibles" << std::endl;
    }
    std::cout << std::endl;
}

void Jugador::insertar(Ficha ficha)
{
    this->lista_fichas.insertAtEnd(ficha);
}
