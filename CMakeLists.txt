cmake_minimum_required(VERSION 3.30)
project(scrabble)

set(CMAKE_CXX_STANDARD 20)

add_executable(scrabble main.cpp
        src/Casilla.cpp
        include/Casilla.h
        src/Tablero.cpp
        include/Tablero.h
        src/Ficha.cpp
        include/Ficha.h
        src/Jugador.cpp
        include/Jugador.h
        src/ManejadorFichas.cpp
        include/ManejadorFichas.h
)
