#ifndef CASILLA_H
#define CASILLA_H
#include "Ficha.h"

class Casilla
{
private:
    Ficha ficha;
    bool esEditable;

public:
    explicit Casilla(char _simbolo, int puntos);

    void bloquear();

    [[nodiscard]] char obtenerSimbolo() const;

    [[nodiscard]] bool estaBloqueada() const;

    void setFicha(char _sym, int pts);

    [[nodiscard]] int obtener_puntos() const;

};
#endif //CASILLA_H
