#include "../../include/utilidades/Utilidad.h"

int Utilidad::getRandomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max - 1);
    return distrib(gen);
}

std::string Utilidad::eliminar_espacios(const std::string& cadena)
{
    std::string resultado = cadena;

    // Eliminar espacios al inicio
    resultado.erase(0, resultado.find_first_not_of(' '));

    // Eliminar espacios al final
    resultado.erase(resultado.find_last_not_of(' ') + 1);

    // Eliminar espacios intermedios
    size_t posicion = 0;
    while ((posicion = resultado.find(' ', posicion)) != std::string::npos)
    {
        resultado.erase(posicion, 1);
    }

    return resultado;
}
