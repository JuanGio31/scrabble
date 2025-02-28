//
// Created by giovani on 20/02/25.
//
#pragma once
#include <stdexcept>

/**
 * Constructor de class LinkedList generica.
 */
template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->_size = 0;
}

/**
 * Funcion que devuelve el tamanio de la lista.
 * @return el tamanio de la lista.
 */
template <typename T>
int LinkedList<T>::size() const
{
    return this->_size;
}

template <typename T>
bool LinkedList<T>::contains(T object)
{
    auto* current = this->head;
    while (current)
    {
        if (current->value == object)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

/**
 * Metodo para agregar un elemento al final de la lista.
 * @param data elemento a agregar a la lista.
 */
template <typename T>
void LinkedList<T>::insertAtEnd(T data)
{
    // auto* temp = new Node;
    // temp->next = nullptr;
    // temp->value = data;
    auto* temp = new Node(data);
    if (this->head == nullptr)
    {
        this->head = temp;
    }
    else
    {
        auto* pointer = this->head;
        while (pointer->next)
        {
            pointer = pointer->next;
        }
        pointer->next = temp;
    }
    ++this->_size;
}

/**
 * Metodo para agregar un elemento al inicio de la lista.
 * @param data elemento a agregar a la lista.
 */
template <typename T>
void LinkedList<T>::insertAtHead(T data)
{
    // auto* temp = new Node;
    // temp->value = data;
    // temp->next = nullptr;

    auto* temp = new Node(data);
    if (this->head == nullptr)
    {
        this->head = temp;
    }
    else
    {
        auto* pointer = this->head;
        this->head = temp;
        temp->next = pointer;
    }
    ++this->_size;
}

/**
 * Metodo para eliminar un elemento al inicio de la lista.
 */
template <typename T>
void LinkedList<T>::deleteAtHead()
{
    if (this->head == nullptr)
    {
        throw std::runtime_error("Lista vacia");
    }
    auto* temp = this->head;
    this->head = this->head->next;
    delete temp;
    temp = nullptr;
    --this->_size;
}

/**
 * Metodo para eliminar un elemento al final de la lista.
 */
template <typename T>
void LinkedList<T>::deleteAtEnd()
{
    if (this->head == nullptr)
        throw std::runtime_error("Lista vacia");

    if (this->head->next == nullptr)
    {
        delete this->head;
        this->head = nullptr;
    }
    else
    {
        auto* current = this->head;
        while (current->next->next != nullptr)
            current = current->next;
        delete current->next;
        current->next = nullptr;
    }
    --this->_size;
}

/**
 * Metodo para buscar un elemento dentro de la lista segun un indice.
 * @param index indice a buscar.
 * @return elemento segun el indice dado.
 */
template <typename T>
T LinkedList<T>::search(int index)
{
    if (this->head == nullptr)
        throw std::runtime_error("Lista vacia");

    auto* current = this->head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index)
        {
            return current->value;
        }
        current = current->next;
        ++count;
    }
    throw std::runtime_error("Indice fuera de rango");
}

/**
 * Funcion para determinar si la lista esta vacia.
 * @return 1 si es falso, 0 si es verdadero.
 */
template <typename T>
bool LinkedList<T>::empty() const
{
    return this->head == nullptr;
}

/**
 * Destructor.
 */
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (this->head != nullptr)
    {
        auto* aux = this->head;
        this->head = this->head->next;
        delete aux;
        aux = nullptr;
    }
}

/**
 * Funcion que sirve para eliminar un elemento de la lista segun dado
 * un indice el cual debe estar dentro del rango de 0 y el tamanio de la lista -1
 * @param index indice del elemento a eliminar
 * @return valor booleano para la facil gestion de errores
 */
template <typename T>
bool LinkedList<T>::deleteAt(int index)
{
    // Verificar si el índice está dentro del rango válido
    if (index < 0 || index >= _size)
    {
        return false;
    }

    if (index == 0)
    {
        deleteAtHead();
    }
    else if (index == _size - 1)
    {
        deleteAtEnd();
    }
    else
    {
        // Eliminar un nodo en el medio de la lista
        Node* current = this->head;
        // Recorrer hasta el nodo anterior al que se desea eliminar
        for (int i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }
        Node* aEliminar = current->next;
        current->next = aEliminar->next;
        delete aEliminar; // Liberar la memoria del nodo
        --this->_size; // Decrementar el tamaño de la lista
    }
    return true;
}


template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::obtenerCola(Node* _head)
{
    while (_head && _head->next)
    {
        _head = _head->next;
    }
    return _head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::quick_sort_rec(Node* _head, Node* cola)
{
    if (!_head || _head == cola)
    {
        return _head;
    }

    Node *newHead = nullptr, *newCola = nullptr;
    Node* pivote = particion(_head, cola, &newHead, &newCola);

    if (newHead != pivote)
    {
        auto* temp = newHead;
        while (temp->next != pivote)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    pivote->next = quick_sort_rec(pivote->next, newCola);
    return newHead;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::particion(Node* inicio, Node* fin, Node** newHead, Node** newCola)
{
    auto pivote = fin;
    Node *prev = nullptr, *curr = inicio, *cola = pivote, *temp = nullptr;

    *newHead = nullptr;
    *newCola = pivote;

    while (curr != pivote)
    {
        if (curr->value < pivote->value)
        {
            if (*newHead == nullptr)
            {
                *newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            temp = curr->next;
            curr->next = nullptr;
            cola->next = curr;
            cola = curr;
            curr = temp;
        }
    }

    if (*newHead == nullptr)
    {
        *newHead = pivote;
    }
    *newCola = cola;

    return pivote;
}

template <typename T>
void LinkedList<T>::quick_sort()
{
    this->head = quick_sort_rec(this->head, LinkedList<T>::obtenerCola(this->head));
}
