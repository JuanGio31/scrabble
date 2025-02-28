//
// Created by giovani on 20/02/25.
//
#pragma once

/**
 * Constructor de class QueueG
 */
template <typename T>
Queue<T>::Queue()
{
    this->front = nullptr;
    this->_size = 0;
}

/**
 * Funcion para determinar si la cola esta vacia.
 * @return true/false.
 */
template <typename T>
bool Queue<T>::empty() const
{
    return this->front == nullptr;
}

/**
 * Funcion para eliminar el frente de la cola y lo devuelve.
 * @return elemento de la cola.
 */
template <typename T>
T Queue<T>::dequeue()
{
    if (this->front == nullptr) throw std::runtime_error("Cola vacia");

    //T data = this->front->value;
    T data = std::move(this->front->value);
    auto* temp = this->front;
    this->front = this->front->next;
    delete temp;
    --this->_size;
    return data;
}

/**
 * Funcion para determinar el tamanio de la cola.
 * @return tamanio de la cola.
 */
template <typename T>
int Queue<T>::size() const
{
    return this->_size;
}

/**
 * Funcion que devuelve el frente de la cola sin eliminarlo.
 * @return frente de la cola.
 */
template <typename T>
T Queue<T>::peek()
{
    return this->front->value;
}

/**
 * Metodo para agregar un elemento a la cola.
 * @param data elemento a agregar.
 */
template <typename T>
void Queue<T>::enqueue(T data)
{
    // auto* temp = new Node;
    // temp->next = nullptr;
    // temp->value = data;
    auto* temp = new Node(data);
    if (this->front == nullptr)
    {
        this->front = temp;
    }
    else
    {
        auto* pointer = this->front;
        while (pointer->next) { pointer = pointer->next; }
        pointer->next = temp;
    }
    ++this->_size;
}

template <typename T>
Queue<T>::~Queue()
{
    while (this->front != nullptr)
    {
        dequeue();
    }
}

template <typename T>
void Queue<T>::rotar()
{
    auto* aux = this->dequeue();
    this->enqueue(aux);
}
