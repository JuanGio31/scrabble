#include "../../include/estructuras/Stack.h"

#include <stdexcept>

/**
 * Constructor de class StackG.
 */
template <typename T>
Stack<T>::Stack()
{
    this->top = nullptr;
    _size = 0;
}

/**
 * Destructor.
 */
template <typename T>
Stack<T>::~Stack()
{
    while (this->top != nullptr)
    {
        auto* aux = top;
        top = top->next;
        delete aux;
    }
}

/**
 * Funcion que devuelve el tamanio de la pila.
 * @return tamanio de la pila.
 */
template <typename T>
int Stack<T>::size() const
{
    return _size;
}

/**
 * Funcion para saber si la pila esta vacia.
 * @return true/false.
 */
template <typename T>
bool Stack<T>::empty()
{
    return top == nullptr;
}

/**
 * Metodo para agregar un elemento a la pila.
 * @param _data elemento a agregar a la pila.
 */
template <typename T>
void Stack<T>::push(T _data)
{
    Nodo* aux = new Nodo(_data);
    //aux->value = _data;
    aux->next = top;
    //auto* temp = Nodo(_data, top);
    top = aux;
    _size++;
}

/**
 * Funcion para eliminar un elemento de la pila y devoverlo.
 * @return elemento de la pila.
 */
template <typename T>
T Stack<T>::pop()
{
    if (empty())
    {
        throw std::runtime_error("Pila vacia");
    }
    T data = top->value;
    auto* aux = top;
    top = top->next;
    delete aux;
    _size--;
    return data;
}

/**
 * Funcion que devuelve la cima de la pila.
 * @return cima.
 */
template <typename T>
T Stack<T>::peek()
{
    if (empty())
    {
        throw std::runtime_error("Pila vacia");
    }
    return this->top->value;
}
