# 0 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/cmake-build-debug-coverage//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/../include/Casilla.h" 1


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
# 4 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/../include/Casilla.h" 2

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
# 2 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp" 2

Casilla::Casilla(char _simbolo, int puntos)
{
    this->esEditable = true;
    this->ficha.setLetra(_simbolo);
    this->ficha.setPuntos(puntos);
}

void Casilla::bloquear()
{
    this->esEditable = false;
}

char Casilla::obtenerSimbolo() const
{
    return this->ficha.obtenerLetra();
}

bool Casilla::estaBloqueada() const
{
    return !this->esEditable;
}

void Casilla::setFicha(char _sym, int pts)
{
    this->ficha.setLetra(_sym);
    this->ficha.setPuntos(pts);
}

int Casilla::obtener_puntos() const
{
    return this->ficha.obtenerPuntos();
}
