//
// Created by giovani on 20/02/25.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node* next;

        explicit Node(T val, Node* nxt = nullptr) : value(val), next(nxt)
        {
        }
    } * head;

    int _size;

    static Node* obtenerCola(Node* _head);
    static Node* quick_sort_rec(Node* _head, Node* cola);
    static Node* particion(Node* inicio, Node* fin, Node** newHead, Node** newCola);

public:
    LinkedList();

    ~LinkedList();

    void quick_sort();

    void insertAtHead(T data);

    void insertAtEnd(T data);

    void deleteAtHead();

    void deleteAtEnd();

    T search(int index);

    bool deleteAt(int index);

    [[nodiscard]] bool empty() const;

    [[nodiscard]] int size() const;

    bool contains(T object);

    //constructor de copia con copia profunda.
    LinkedList(const LinkedList& other)
        : head(nullptr), _size(0)
    {
        Node* current = other.head;
        while (current != nullptr)
        {
            // Inserta una copia del valor en la lista actual.
            this->insertAtEnd(current->value);
            current = current->next;
        }
    }

    // Operador de asignación con copia profunda.
    LinkedList& operator=(const LinkedList& other)
    {
        if (this != &other)
        {
            // Primero, liberar la memoria actual.
            while (this->head != nullptr)
            {
                Node* temp = this->head;
                this->head = this->head->next;
                delete temp;
            }
            _size = 0;

            // Copiar los elementos de 'other'
            Node* current = other.head;
            while (current != nullptr)
            {
                this->insertAtEnd(current->value);
                current = current->next;
            }
        }
        return *this;
    }


    // Constructor de movimiento.
    LinkedList(LinkedList&& other) noexcept
        : head(other.head), _size(other._size)
    {
        other.head = nullptr;
        other._size = 0;
    }

    // Operador de asignación de movimiento.
    LinkedList& operator=(LinkedList&& other) noexcept
    {
        if (this != &other)
        {
            // Liberar la memoria actual.
            while (this->head != nullptr)
            {
                Node* temp = this->head;
                this->head = this->head->next;
                delete temp;
            }
            // Transferir la propiedad de los recursos.
            head = other.head;
            _size = other._size;
            other.head = nullptr;
            other._size = 0;
        }
        return *this;
    }
};
#include "../../src/estructuras/LinkedList.tpp"
#endif //LINKEDLIST_H
