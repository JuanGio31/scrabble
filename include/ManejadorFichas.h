#ifndef MANEJADORFICHAS_H
#define MANEJADORFICHAS_H
#include "Ficha.h"

class ManejadorFichas
{
private:
    Ficha* fichas[5];

public:
    ManejadorFichas()
    {
        for (int i = 0; i < 5; ++i)
        {
            fichas[i] = new Ficha();
        }
    }

    ~ManejadorFichas()
    {
        for (int i = 0; i < 5; ++i)
        {
            delete fichas[i];
        }
    }
};
#endif //MANEJADORFICHAS_H
