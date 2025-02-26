#include "../include/ManejadorFichas.h"
// #include "estructuras/LinkedList.cpp"
#include <iostream>

#include "../include/utilidades/Utilidad.h"

void ManejadorFichas::generarFichas() const
{
    const int n = lista_palabras.size(); // obtener el tamanio de la lista

    // insertar las fichas en la lista de fichas
    for (int i = 0; i < n; ++i)
    {
        const char* arreglo = lista_palabras.search(i).c_str(); //arr[i].c_str();
        const char* ptr = arreglo;
        while (*ptr != '\0')
        {
            // this->lista_fichas->insertAtEnd({*ptr, Utilidad::getRandomInt(1, 5)});
            fichas_list.insertAtEnd({*ptr, Utilidad::getRandomInt(1, 5)});
            ptr++;
        }
    }
}

ManejadorFichas::ManejadorFichas(LinkedList<std::string>& lista_palabras, LinkedList<Ficha>& fichas_list,
                                 Queue<Jugador>& jugadores_en_juego): lista_palabras(lista_palabras),
                                                                      fichas_list(fichas_list),
                                                                      jugadores_en_juego(jugadores_en_juego)
{
}

void ManejadorFichas::repartir() const
{
    this->generarFichas();
    const int n = fichas_list.size();
    const int div = n / jugadores_en_juego.size();
    const int size_jugadores = this->jugadores_en_juego.size();

    int index = 0;
    for (int i = 0; i < size_jugadores; ++i)
    {
        auto actual = jugadores_en_juego.dequeue();
        if (index == div)
        {
            int resto = fichas_list.size() - div;
            while (resto < n)
            {
                actual.insertar(fichas_list.search(resto));
                resto++;
            }
        }
        else
        {
            for (index = 0; index < div; ++index)
            {
                actual.insertar(fichas_list.search(index));
            }
        }
        jugadores_en_juego.enqueue(actual); //aqui ocurre el error
    }

   // ordenarFichas();
}

void ManejadorFichas::ordenarFichas() const
{
    auto aux = jugadores_en_juego.dequeue();
    aux.ordenar();
    jugadores_en_juego.enqueue(aux);
}
