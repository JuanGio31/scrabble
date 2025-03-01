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

    void setLetra(char _sym);
    void setPuntos(int _pts);

    //comparacion de objetos
    //sobrecarga de operador <, para facilitar la comparacion
    //de los atributos
    bool operator>(const Ficha& otro) const
    {
        return puntos > otro.puntos;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ficha& ficha)
    {
        os << ficha.puntos;
        return os;
    }
};

#include "../src/Ficha.tpp"
#endif //FICHA_H
