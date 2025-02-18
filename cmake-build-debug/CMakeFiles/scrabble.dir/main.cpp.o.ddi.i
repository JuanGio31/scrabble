# 0 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/main.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/main.cpp"
# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/include/Tablero.h" 1


# 1 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/include/Casilla.h" 1



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
# 4 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/include/Tablero.h" 2

class Tablero
{
private:
    static const int FILAS = 15;
    static const int COLUMNAS = 15;
    Casilla* casillas[FILAS][COLUMNAS];
    void iniciar_tablero();
    void bloquear_casilla();

public:
    Tablero();
    ~Tablero();
    void pintar_tablero();
};
# 2 "/home/giovani/Documentos/Tareas/1S2025/EDD/Proyectos/scrabble/main.cpp" 2

int main()
{
    Tablero tablero;
    tablero.pintar_tablero();
    return 0;
}
