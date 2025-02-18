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
# 2 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Casilla.cpp" 2

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
