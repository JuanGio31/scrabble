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
        src/Archivo.cpp
        src/Game.cpp
        include/Game.h
        include/estructuras/Queue.h
        src/estructuras/Queue.cpp
        include/estructuras/LinkedList.h
        src/estructuras/LinkedList.cpp
)
