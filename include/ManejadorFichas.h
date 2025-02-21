#ifndef MANEJADORFICHAS_H
#define MANEJADORFICHAS_H
#include "Ficha.h"
#include "Jugador.h"
#include "estructuras/LinkedList.h"

class ManejadorFichas
{
private:
    LinkedList<Ficha> lista_fichas;

public:
    explicit ManejadorFichas(LinkedList<Ficha> _lista);
};
#endif //MANEJADORFICHAS_H
