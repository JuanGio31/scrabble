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
    explicit Ficha(char _letra);

    [[nodiscard]] int obtenerPuntos() const;
    [[nodiscard]] char obtenerLetra() const;
};
#endif //FICHA_H
