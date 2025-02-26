# 0 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Ficha.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/cmake-build-debug-coverage//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Ficha.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/../include/Ficha.h" 1



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




    bool operator<(const Ficha& otro) const
    {
        return puntos < otro.puntos;
    }
};
# 2 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Ficha.cpp" 2

Ficha::Ficha()
{
    this->letra = ' ';
    this->puntos = 0;
}

Ficha::Ficha(char _letra, int _puntos)
{
    this->letra = _letra;
    this->puntos = _puntos;
}

Ficha::Ficha(char _letra)
{
    this->letra = _letra;
    this->puntos = 0;
}

char Ficha::obtenerLetra() const
{
    return this->letra;
}

void Ficha::setLetra(char _sym)
{
    this->letra = _sym;
}

void Ficha::setPuntos(int _pts)
{
    this->puntos = _pts;
}

int Ficha::obtenerPuntos() const
{
    return this->puntos;
}
