#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

#include "../include/ManejadorFichas.h"

class Archivo
{
private:
    ManejadorFichas fichas;
    std::string path;

public:
    explicit Archivo(std::string _path)
    {
        this->path = std::move(_path);
    }

    void leerArchivo()
    {
        std::ifstream archivo(this->path);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo: " << path << std::endl;
            return;
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
                std::cout << cadena << " ";
            }
        }

        archivo.close(); // Cierra el archivo
    }
};
