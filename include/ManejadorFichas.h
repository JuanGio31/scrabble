#ifndef MANEJADORFICHAS_H
#define MANEJADORFICHAS_H

class ManejadorFichas
{
private:
    LinkedList<std::string>& lista_palabras;
    LinkedList<Ficha>& fichas_list;
    Queue<Jugador>& jugadores_en_juego;

    void generarFichas() const;
    //void ordenarFichas() const;

public:
    ManejadorFichas(
        LinkedList<std::string>& lista_palabras,
        LinkedList<Ficha>& fichas_list,
        Queue<Jugador>& jugadores_en_juego);

    void repartir() const;
};

#include "../src/ManejadorFichas.tpp"
#endif //MANEJADORFICHAS_H
