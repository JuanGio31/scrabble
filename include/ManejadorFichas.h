#ifndef MANEJADORFICHAS_H
#define MANEJADORFICHAS_H

#include "Ficha.h"
#include "Jugador.h"
#include "estructuras/LinkedList.h"
#include "estructuras/Queue.h"
//#include "../src/estructuras/Queue.cpp"

class ManejadorFichas
{
private:
    LinkedList<Ficha>* lista_fichas;

public:
    ManejadorFichas();

    ~ManejadorFichas();

    void generarListaFichas(LinkedList<std::string> lista) const;

    void repartirFichas(Queue<Jugador>& jugadores) const;
};
#endif //MANEJADORFICHAS_H
