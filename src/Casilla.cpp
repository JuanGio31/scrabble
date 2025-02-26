#include "../include/Casilla.h"

Casilla::Casilla(char _simbolo, int puntos)
{
    this->esEditable = true;
    this->ficha.setLetra(_simbolo);
    this->ficha.setPuntos(puntos);
}

void Casilla::bloquear()
{
    this->esEditable = false;
}

char Casilla::obtenerSimbolo() const
{
    return this->ficha.obtenerLetra();
}

bool Casilla::estaBloqueada() const
{
    return !this->esEditable;
}

void Casilla::setFicha(char _sym, int pts)
{
    this->ficha.setLetra(_sym);
    this->ficha.setPuntos(pts);
}

int Casilla::obtener_puntos() const
{
    return this->ficha.obtenerPuntos();
}
