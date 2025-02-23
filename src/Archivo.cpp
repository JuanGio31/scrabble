#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include "../include/estructuras/LinkedList.h"
#include "../include/utilidades/Utilidad.h"

class Archivo
{
private:
    size_t total_letras;
    std::string path;

public:
    explicit Archivo(std::string _path)
    {
        this->path = std::move(_path);
        this->total_letras = 0;
    }

    /**
     * Funcion que devuelve lee el archivo para despues almacenar las palabras en una lista
     * @return lista de palabras
     */
    [[nodiscard]] LinkedList<std::string> leer_archivo()
    {
        LinkedList<std::string> palabras;
        std::ifstream archivo(this->path);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo: " << path << std::endl;
            return palabras;
        }

        std::string linea;
        while (std::getline(archivo, linea))
        {
            // Lee el archivo línea por línea
            std::stringstream ss(linea); // Crea un stringstream para la línea
            std::string cadena;

            while (std::getline(ss, cadena, ','))
            {
                // Divide la línea por comas
                //std::cout << cadena << " ";
                palabras.insertAtEnd(cadena);

                //sumar el total de letras
                total_letras = total_letras + cadena.length();
            }
        }
        archivo.close(); // Cierra el archivo
        return palabras;
    }

    [[nodiscard]] size_t obtener_total_letras() const
    {
        return total_letras;
    }
};
