cmake_minimum_required(VERSION 3.30)
project(scrabble)

set(CMAKE_CXX_STANDARD 20)

add_executable(scrabble main.cpp
        src/Casilla.tpp
        include/Casilla.h
        src/Tablero.tpp
        include/Tablero.h
        src/Ficha.tpp
        include/Ficha.h
        src/Jugador.tpp
        include/Jugador.h
        src/ManejadorFichas.tpp
        include/ManejadorFichas.h
        src/Game.tpp
        include/Game.h
        include/estructuras/Queue.h
        src/estructuras/Queue.tpp
        include/estructuras/LinkedList.h
        src/estructuras/LinkedList.tpp
        include/utilidades/Utilidad.h
        src/utilidades/Utilidad.tpp
        src/estructuras/Stack.tpp
        include/estructuras/Stack.h
        include/Reporte.h
        include/Archivo.h
)
