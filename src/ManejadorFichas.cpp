#include "../include/ManejadorFichas.h"
//#include "estructuras/LinkedList.cpp"
#include <iostream>

#include "../include/utilidades/Utilidad.h"

ManejadorFichas::ManejadorFichas()
{
    this->lista_fichas = new LinkedList<Ficha>;
}


void ManejadorFichas::generarListaFichas(LinkedList<std::string> lista) const
{
    const int n = lista.size(); //obtener el tamanio de la lista
    auto* arr = new std::string[n];

    //pasar los elementos de la lista a aun array
    for (int i = 0; i < n; ++i)
    {
        arr[i] = lista.search(i);
        //lista.deleteAtHead();
    }

    //insertar las fichas en la lista de fichas
    for (int i = 0; i < n; ++i)
    {
        const char* arreglo = arr[i].c_str();
        const char* ptr = arreglo;
        while (*ptr != '\0')
        {
            this->lista_fichas->insertAtEnd({*ptr, Utilidad::getRandomInt(1, 5)});
            ptr++;
        }
    }
}

// error -> verificar referencia.
void ManejadorFichas::repartirFichas(Queue<Jugador>& jugadores) const
{
    // for (int i = 0; i < lista_fichas->size(); ++i)
    // {
    //     std::cout << (i + 1) << ".- " << lista_fichas->search(i).obtenerLetra() << " <" << lista_fichas->search(i).
    //         obtenerPuntos() << ">" << std::endl;
    // }


    const int n = this->lista_fichas->size();
    const int div = n / jugadores.size();
    std::cout << "lim-> " << div << std::endl;

    const int size_jugadores = jugadores.size();
    auto* arr = new Jugador[size_jugadores];
    for (int i = 0; i < size_jugadores; ++i)
    {
        //        arr[i] = jugadores->dequeue();
        arr[i] = jugadores.dequeue();
    }

    int index = -1;
    for (int i = 0; i < size_jugadores - 1; ++i)
    {
        int k = 0;
        while (k < div + 1)
        {
            ++index;
            //arr[i].obetener_fichas_list().insertAtEnd(this->lista_fichas->search(index));
            arr[i].insertar(this->lista_fichas->search(index));
            ++k;
        }
    }

    for (int i = index; i < n; ++i)
    {
        //arr[size_jugadores - 1].obetener_fichas_list().insertAtEnd(this->lista_fichas->search(index));
        arr[size_jugadores - 1].insertar(this->lista_fichas->search(i));
        index++;
    }

    for (int i = 0; i < size_jugadores; ++i)
    {
        //jugadores->enqueue(arr[i]);
        jugadores.enqueue(arr[i]);
    }

    delete [] arr;
}

ManejadorFichas::~ManejadorFichas()
{
    //delete lista_fichas;
}
