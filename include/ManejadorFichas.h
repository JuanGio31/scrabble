#ifndef MANEJADORFICHAS_H
#define MANEJADORFICHAS_H

#include "Ficha.h"
#include "Jugador.h"
#include "estructuras/LinkedList.h"
#include "estructuras/Queue.h"

class ManejadorFichas
{
private:
    LinkedList<std::string>& lista_palabras;
    LinkedList<Ficha>& fichas_list;
    Queue<Jugador>& jugadores_en_juego;

    void generarFichas() const;
    void ordenarFichas() const;

public:
    ManejadorFichas(
        LinkedList<std::string>& lista_palabras,
        LinkedList<Ficha>& fichas_list,
        Queue<Jugador>& jugadores_en_juego);

    void repartir() const;
};
#endif //MANEJADORFICHAS_H
