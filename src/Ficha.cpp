#include "../include/Ficha.h"

Ficha::Ficha()
{
    this->letra = ' ';
    this->puntos = 0;
}

Ficha::Ficha(char _letra, int _puntos)
{
    this->letra = _letra;
    this->puntos = _puntos;
}

char Ficha::obtenerLetra()
{
    return this->letra;
}

int Ficha::obtenerPuntos()
{
    return this->puntos;
}
