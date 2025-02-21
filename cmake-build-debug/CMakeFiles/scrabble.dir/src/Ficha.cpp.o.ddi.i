# 0 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/src/Ficha.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/cmake-build-debug//"
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

    int obtenerPuntos();
    char obtenerLetra();
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

char Ficha::obtenerLetra()
{
    return this->letra;
}

int Ficha::obtenerPuntos()
{
    return this->puntos;
}
