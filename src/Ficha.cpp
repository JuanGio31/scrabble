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

Ficha::Ficha(char _letra)
{
    this->letra = _letra;
    this->puntos = 0;
}

char Ficha::obtenerLetra() const
{
    return this->letra;
}

int Ficha::obtenerPuntos() const
{
    return this->puntos;
}
