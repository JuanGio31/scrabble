//
// Created by giovani on 28/02/25.
//

#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "estructuras/LinkedList.h"

class Archivo
{
public:
    explicit Archivo(std::string _path)
    {
        this->path = std::move(_path);
    }

    /**
     * Funcion que devuelve lee el archivo para despues almacenar las palabras en una lista
     * @return lista de palabras
     */
    //[[nodiscard]] LinkedList<std::string>
    void leer_archivo(LinkedList<std::string>* listado) const
    {
        //  LinkedList<std::string> palabras;
        std::ifstream archivo(this->path);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo: " << path << std::endl;
            //return palabras;
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
                //palabras.insertAtEnd(cadena);
                listado->insertAtEnd(cadena);
            }
        }
        archivo.close(); // Cierra el archivo
        //return palabras;
    }

private:
    std::string path;
};
#endif //ARCHIVO_H
