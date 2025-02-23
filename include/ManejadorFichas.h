#ifndef MANEJADORFICHAS_H
#define MANEJADORFICHAS_H
#include "Ficha.h"
#include "Jugador.h"
#include "estructuras/LinkedList.h"

class ManejadorFichas
{
private:
    LinkedList<Ficha> lista_fichas;
    bool existe(int index);

public:
    explicit ManejadorFichas(const LinkedList<Ficha>& _lista);
    Ficha obtener_ficha(int index);
    void mostrar_fichas_disponibles();
    void eliminar(int index);
};
#endif //MANEJADORFICHAS_H
