#include "../include/Casilla.h"

Casilla::Casilla(char _simbolo, int pos_x, int pos_y)
{
    this->simbolo = _simbolo;
    this->posX = pos_x;
    this->posY = pos_y;
    this->esEditable = true;
}

Casilla::Casilla(int pos_x, int pos_y)
{
    this->simbolo = '#';
    this->posX = pos_x;
    this->posY = pos_y;
    this->esEditable = true;
}

void Casilla::asignar_simbolo(char _simbolo)
{
    this->simbolo = _simbolo;
}

void Casilla::bloquear()
{
    this->esEditable = false;
}

char Casilla::obtenerSimbolo()
{
    return this->simbolo;
}

int Casilla::obtenerPosX()
{
    return this->posX;
}

int Casilla::obtenerPosY()
{
    return this->posY;
}
