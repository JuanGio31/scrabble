//
// Created by giovani on 21/02/25.
//

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>


class Utilidad
{
public:
    static int getRandomInt(int min, int max);
    static std::string eliminar_espacios(const std::string& cadena);
};


#endif //RANDOMGENERATOR_H
