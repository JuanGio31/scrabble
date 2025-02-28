#ifndef REPORTE_H
#define REPORTE_H
#include <iostream>

#include "Jugador.h"
#include "estructuras/Queue.h"
#include "estructuras/Stack.h"

class Reporte
{
private:
    Queue<Jugador>& jugadores;
    Stack<std::string>& palabras_jugadas;
    LinkedList<std::string>& str_no_encontradas;


    void ordenar();
    static void swap(Jugador& p1, Jugador& p2) noexcept;
    static void bubble_sort(Jugador arr[], int n);

    void imprimir_palabras_jugadas();
    void imprimir_palabras_no_encontradas();

public:
    explicit Reporte(Queue<Jugador>& jugadores, Stack<std::string>& str_jugadas,
                     LinkedList<std::string>& str_no_encontradas);
    Reporte() = delete;
    void setQueue(Queue<Jugador>& p);
    void imprimirReporte();
};

inline void Reporte::ordenar()
{
    const int len = this->jugadores.size();
    auto* arr = new Jugador[len];

    for (int i = 0; i < len; ++i)
    {
        arr[i] = jugadores.dequeue();
    }

    bubble_sort(arr, len);

    for (int i = 0; i < len; ++i)
    {
        jugadores.enqueue(arr[i]);
    }

    delete[] arr;
}

inline void Reporte::swap(Jugador& p1, Jugador& p2) noexcept
{
    auto aux = p1;
    p1 = p2;
    p2 = aux;
}

inline void Reporte::bubble_sort(Jugador arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j].obtener_puntos() < arr[j + 1].obtener_puntos())
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

inline void Reporte::imprimir_palabras_jugadas()
{
    std::cout << "PALABRAS ENCONTRADAS" << std::endl;
    const int len = this->palabras_jugadas.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << (i + 1) << ".- " << palabras_jugadas.pop() << std::endl;
    }
    std::cout << std::endl;
}

inline void Reporte::imprimir_palabras_no_encontradas()
{
    std::cout << "PALABRAS NO ENCONTRADAS" << std::endl;
    const int len = this->str_no_encontradas.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << (i + 1) << ".- " << str_no_encontradas.search(i) << std::endl;
    }
    std::cout << std::endl;
}

inline Reporte::Reporte(Queue<Jugador>& jugadores, Stack<std::string>& str_jugadas,
                        LinkedList<std::string>& str_no_encontradas): jugadores(jugadores),
                                                                      palabras_jugadas(str_jugadas),
                                                                      str_no_encontradas(str_no_encontradas)
{
}


inline void Reporte::setQueue(Queue<Jugador>& p)
{
    this->jugadores = p;
}

inline void Reporte::imprimirReporte()
{
    if (jugadores.empty())
    {
        std::cout << "--------No Reportes--------";
    }
    else
    {
        ordenar();
        auto* temp = jugadores.getFront();
        int index = 1;
        while (temp != nullptr)
        {
            std::cout << index << ".- " << temp->value.obtener_nombre()
                << "\t\tPuntos: " << temp->value.obtener_puntos() << ".\t\tMovimientos: " << temp->value.
                obtener_movimientos() << std::endl;
            temp = temp->next;
            index++;
        }

        imprimir_palabras_jugadas();
        imprimir_palabras_no_encontradas();
    }
}
#endif //REPORTE_H
