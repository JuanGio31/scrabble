#ifndef FICHA_H
#define FICHA_H

class Ficha
{
private:
    char letra;
    int puntos;

public:
    Ficha();

    Ficha(char _letra, int _puntos);

    int obtenerPuntos();
    char obtenerLetra();
};
#endif //FICHA_H
