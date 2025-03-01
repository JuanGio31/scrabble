#pragma once

inline Jugador::Jugador()
{
    this->nombre = "";
    this->movimientos = 0;
    this->puntos = 0;
}

inline Jugador::Jugador(const std::string& _nombre)
{
    this->nombre = _nombre;
    this->movimientos = 0;
    this->puntos = 0;
}

inline void Jugador::restar_puntos(int pts)
{
    this->puntos = this->puntos - pts;
}

inline void Jugador::aumentar_movimiento()
{
    this->movimientos++;
}

[[nodiscard]] inline std::string Jugador::obtener_nombre() const
{
    return this->nombre;
}

[[nodiscard]] inline int Jugador::obtener_movimientos() const
{
    return this->movimientos;
}

inline int Jugador::obtener_puntos() const
{
    return this->puntos;
}

inline void Jugador::sumar_puntos(int pts)
{
    std::cout << "Palabra encontrada! +" << pts << " pts." << std::endl;
    this->puntos += pts;
}

inline void Jugador::set_nombre(std::string _nombre)
{
    this->nombre = std::move(_nombre);
}

inline bool Jugador::existe(const int index)
{
    try
    {
        lista_fichas.search(index);
        return true;
    }
    catch ([[maybe_unused]] std::exception& e)
    {
        return false;
    }
}

inline void Jugador::eliminar(const int index)
{
    lista_fichas.deleteAt(index);
}

inline void Jugador::ordenar()
{
    //this->lista_fichas.quick_sort();
}

inline Ficha Jugador::obtener_ficha(const int index)
{
    if (existe(index))
    {
        return lista_fichas.search(index);
    }
    //Manejar exception
    throw std::out_of_range("Indice fuera de rango");
}

inline void Jugador::mostrar_fichas_disponibles()
{
    std::cout << std::endl;;
    if (!lista_fichas.empty())
    {
        std::cout << "letra   puntos" << std::endl;
        std::cout << "  ↓       ↓" << std::endl;
        std::cout << " {A}     [10]." << std::endl;

        const int size = this->lista_fichas.size(); //obtener tamanio de la lista

        int j = 0;
        for (int i = 0; i < size; ++i)
        {
            std::string whitespace = "\t\t\t";
            if (j > 4)
            {
                whitespace = "\n";
                j = -1;
            }
            std::cout << (i + 1) << ".-  {" << lista_fichas.search(i).obtenerLetra() << "} [" << lista_fichas.
                search(i).
                obtenerPuntos() << "]" << whitespace;
            j++;
        }
    }
    else
    {
        std::cout << "No hay fichas disponibles" << std::endl;
    }
    std::cout << std::endl;
}

inline void Jugador::insertar(Ficha ficha)
{
    this->lista_fichas.insertAtEnd({ficha.obtenerLetra(), ficha.obtenerPuntos()});
}

inline int Jugador::obtener_num_fichas_restantes() const
{
    return this->lista_fichas.size();
}

inline LinkedList<Ficha> Jugador::get_lista_fichas()
{
    return this->lista_fichas;
}
