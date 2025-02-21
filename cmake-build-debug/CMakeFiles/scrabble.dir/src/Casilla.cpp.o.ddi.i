# 0 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/../include/Casilla.h" 1



class Casilla
{
private:
    char simbolo;


    bool esEditable;

public:


    explicit Casilla(char _simbolo);
    Casilla();

    void asignar_simbolo(char _simbolo);
    void bloquear();
    [[nodiscard]] char obtenerSimbolo() const;


};
# 2 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp" 2
# 29 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp"
Casilla::Casilla()
{
    this->simbolo = '#';
    this->esEditable = false;
}

Casilla::Casilla(char _simbolo)
{
    this->simbolo = _simbolo;
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

char Casilla::obtenerSimbolo() const
{
    return this->simbolo;
}
