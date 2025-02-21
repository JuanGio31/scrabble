#ifndef CASILLA_H
#define CASILLA_H

class Casilla
{
private:
    char simbolo;
    // int posX;
    // int posY;
    bool esEditable;

public:
    // Casilla(char _simbolo, int pos_x, int pos_y);
    // Casilla(int pos_x, int pos_y);
    explicit Casilla(char _simbolo);
    Casilla();

    void asignar_simbolo(char _simbolo);
    void bloquear();
    [[nodiscard]] char obtenerSimbolo() const;
    // [[nodiscard]] int obtenerPosX() const;
    // [[nodiscard]] int obtenerPosY() const;
};
#endif //CASILLA_H
