#pragma once
inline Casilla::Casilla(char _simbolo, int puntos)
{
    this->esEditable = true;
    this->ficha.setLetra(_simbolo);
    this->ficha.setPuntos(puntos);
}

inline void Casilla::bloquear()
{
    this->esEditable = false;
}

inline char Casilla::obtenerSimbolo() const
{
    return this->ficha.obtenerLetra();
}

inline bool Casilla::estaBloqueada() const
{
    return !this->esEditable;
}

inline void Casilla::setFicha(char _sym, int pts)
{
    this->ficha.setLetra(_sym);
    this->ficha.setPuntos(pts);
}

inline int Casilla::obtener_puntos() const
{
    return this->ficha.obtenerPuntos();
}
