#pragma once

inline Ficha::Ficha()
{
    this->letra = ' ';
    this->puntos = 0;
}

inline Ficha::Ficha(char _letra, int _puntos)
{
    this->letra = _letra;
    this->puntos = _puntos;
}

inline Ficha::Ficha(char _letra)
{
    this->letra = _letra;
    this->puntos = 0;
}

inline char Ficha::obtenerLetra() const
{
    return this->letra;
}

inline void Ficha::setLetra(char _sym)
{
    this->letra = _sym;
}

inline void Ficha::setPuntos(int _pts)
{
    this->puntos = _pts;
}

inline int Ficha::obtenerPuntos() const
{
    return this->puntos;
}
