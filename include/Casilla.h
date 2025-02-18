#ifndef CASILLA_H
#define CASILLA_H

class Casilla
{
private:
    char simbolo;
    int posX;
    int posY;
    bool esEditable;

public:
    Casilla(char _simbolo, int pos_x, int pos_y);

    Casilla(int pos_x, int pos_y);

    ~Casilla() = default;

    void asignar_simbolo(char _simbolo);
    void bloquear();
    char obtenerSimbolo();
    int obtenerPosX();
    int obtenerPosY();
};
#endif //CASILLA_H
