#include "../include/ManejadorFichas.h"
#include "estructuras/LinkedList.cpp"
#include <iostream>

ManejadorFichas::ManejadorFichas(const LinkedList<Ficha>& _lista)
{
    this->lista_fichas = _lista;
}

bool ManejadorFichas::existe(int index)
{
    try
    {
        lista_fichas.search(index);
        return true;
    }
    catch (std::exception& e)
    {
        return false;
    }
}

void ManejadorFichas::eliminar(int index)
{
    lista_fichas.deleteAt(index);
}


Ficha ManejadorFichas::obtener_ficha(int index)
{
    if (existe(index))
    {
        return lista_fichas.search(index);
    }
    //Manejar exception
    throw std::out_of_range("Indice fuera de rango");
}

void ManejadorFichas::mostrar_fichas_disponibles()
{
    if (!lista_fichas.empty())
    {
        std::cout << "\nletra   puntos" << std::endl;
        std::cout << "  ↓       ↓" << std::endl;
        std::cout << "  A     [10]." << std::endl << std::endl;

        const int size = this->lista_fichas.size(); //obtener tamanio de la lista

        for (int i = 0; i < size; ++i)
        {
            std::string whitespace = (i % 3 == 0) ? "\n" : " "; //operador ternario
            std::cout << std::endl << lista_fichas.search(i).obtenerLetra() << "  [" << lista_fichas.search(i).
                obtenerPuntos() << "]." << whitespace;
        }
    }
    else
    {
        std::cout << "No hay fichas disponibles" << std::endl;
    }
}
